###### YANIV

#include <string_view>
#include <nanolabs/kernel/events/wasmlib.h>
#include <nanolabs/kernel/http/wasmlib.h>
#include <nanolabs/syscall/interface.h>
#include <nanolabs/examples/notifier/wasmlib.h>
#include <nanolabs/examples/notifier/interface.h>
#include <nanolabs/examples/hello/interface.h>

using namespace nano::std;
using namespace nano::system;

using namespace nanolabs::examples::notifier;
using namespace nanolabs::examples::hello;

#define PRINTSTR(name, format) \
        nlog("%s " format, #name, (char*)_head->name.c_str)
#define PRINTENUM(_class, name, format) \
        nlog("%s " format, #name, _class ## _str(_head->name))
#define PRINTVAL(name, format) \
        nlog("%s " format, #name, _head->name)

void on_body_data();

Ptr<void> event_data_prepare(void *opaque)
{
    auto str = (const char *)opaque;
    auto event_arg = new Str(str);

    return event_arg;
}

static unsigned dispatch_counter = 0;

void nano_keyvalue_on_notify()
{
    NLOG_EVENT_START();

    auto msg = (NotifyEventMsg *)nf::events::event_data();
    std::string_view color = msg->color();
    nlog("color %.*s", VSTR_LS(color));
    if (dispatch_counter++ < 11) {
        nf::events::dispatch("@nanolabs/examples/hello", "Event1", event_data_prepare, (void *)"event_A01");
        nf::events::dispatch("@nanolabs/examples/hello", "Event2", event_data_prepare, (void *)"event_A02");
    }
}

void on_headers()
{
    NLOG_EVENT_START();

    int ret = 0;

    nf::http::header_insert("header-to-delete", "value");
    nf::http::header_insert("headername", "headervalue");
    nf::http::header_remove("header-to-delete");

    Str *host = nf::http::header_get("Host", USE_REQUEST);
    if (host == NULL) {
        nlog("host is NULL");
    } else {
        nlog("host is %s", (char*)host->c_str);
    }

    Str *hdrvalue = nf::http::header_get("headername");
    if (hdrvalue == NULL) {
        nlog("headername is NULL");
    } else {
        nlog("headername is %s", (char*)hdrvalue->c_str);
    }

    ret = nf::http::header_remove("accept");
    nlog("remove accept header: ret %d", ret);

    ret = nf::http::header_remove("accept-ranges");
    nlog("remove accept-ranges header: ret %d", ret);

    nf::http::header_insert("accept-ranges", "rangevalue1");
    nf::http::header_insert("accept-ranges", "rangevalue2");
    nf::http::header_remove("accept-ranges");
    nf::http::header_remove("accept-ranges"); // TODO not supported yet. only one header is removed
    nf::http::header_insert("accept-ranges", "rangevalue3");
    nf::http::header_modify("accept-ranges", "RANGEVALUE3");

    uint count = nf::http::headers_count();
    nlog("headers count %u", count);

    List *headers = nf::http::headers_get();
    if (headers == NULL) {
        nlog("no headers");
        return;
    }

    auto request_head = nf::http::request_head_get();
    if (request_head != NULL) {
        if (true) {
            nanolabs::examples::notifier::RPC::BigDataTest test;
            unsigned size = 1 * 1024 * 1024 + 1;
            char *buf = (char *)malloc(size);
            buf[size] = '\0';
            memset(buf, 'x', size);
            test(buf);
        }

        if (false) {
            nanolabs::syscall::RPC::Sleep sleep;
            auto response = sleep(1000);
            nlog("result is %s", response->status().data());
        }

        if (false) {
            nanolabs::syscall::RPC::Sleep sleep;
            sleep.request()->set_ms(2000);
            sleep.call();
            nlog("result is %s", sleep.response()->status().data());
        }

#define _head request_head
        PRINTVAL(http_version, "%u");
        PRINTENUM(nf::http::version_t, http_version, "%s");
        PRINTENUM(nf::http::method_t, method, "%s");
        PRINTSTR(method_str,   "%s");
        PRINTSTR(url,          "%s");
        PRINTSTR(uri_wqs,      "%s");
        PRINTSTR(request_line, "%s");
#undef _head
    }

    auto response_head = nf::http::response_head_get();
    if (response_head != NULL) {
#define _head response_head
        if ((response_head->status == 200) ||
            (response_head->status == 405)) {
            nf::events::listen("@nanolabs/http", "Response_body", on_body_data);
        } else {
            //TODO implement listen_stop
            //nf::events::listen_stop("@nanolabs/http", "Response_body", on_body_data);
        }
        PRINTVAL(status, "%u");
        PRINTSTR(status_line, "%s");
#undef _head
    }

    // TODO use iterator so that the iteration will work.
    // we can't have shmem_t here as it is internal
#if 0
    for (auto iter = headers->next;
            iter != headers; iter = iter->next) {
        auto header_shmem = reinterpret_cast<nf::http::http_header_shmem_t*>(iter.p());
        auto header = &header_shmem->header;
        nlog("%s : %s", (char*)header->name.c_str, (char*)header->value.c_str);
    }
#endif

    nlog("done");
}

void on_body_data()
{
    NLOG_EVENT_START();

    Str *data = nf::http::body_data_get();
    if (data == NULL) {
        nlog("data is NULL");
        return;
    }
    nlog("len %u data:\n%.*s",
            data->len, data->len, (char *)data->c_str);
}

void on_request_done()
{
    NLOG_EVENT_START();

    nlog("done");
}

void on_response_done()
{
    NLOG_EVENT_START();

    nlog("done");
}

void PingAPI(Request &request, Reply &response)
{
    NLOG_EVENT_START();

    response.set_data_ref(request.data_ref());

    nlog("done");
}

void nanoapp_init()
{
    nlog("my_nanoapp_name %s", nf::events::my_nanoapp_name->c_str());

    nf::events::listen("@nanolabs/examples/notifier", "Notify", nano_keyvalue_on_notify);

    nf::events::listen("@nanolabs/http", "Request_headers",  on_headers);
    nf::events::listen("@nanolabs/http", "Response_headers", on_headers);

    nf::events::listen("@nanolabs/http", "Request_body",     on_body_data);
    //nf::events::listen("@nanolabs/http", "Response_body",    on_body_data);

    nf::events::listen("@nanolabs/http", "Request_done",     on_request_done);
    nf::events::listen("@nanolabs/http", "Response_done",    on_response_done);

    nanolabs::examples::hello::RPC::Ping::set_handler(PingAPI);

    nlog("functions registered");
}

