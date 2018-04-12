
#[macro_use]
mod wap;

wap_begin!(|window| {
    let document = wap::get(&window, "document").unwrap();
    let body = wap::get(&document, "body").unwrap();
    wap::set(
        &body,
        "innerHTML",
        "<h1>Hello World</h1>".to_string().into(),
    );
});

fn main() {}
