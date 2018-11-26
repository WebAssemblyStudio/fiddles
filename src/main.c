#define DRASKIA_NP_URL "https://www.pretzel.rocks/api/v1/playing/twitch/draskia"
#define WASM_EXPORT __attribute__((visibility("default")))

#ifndef _V1X1_H
#define _V1X1_H 1
#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define EVENT_MESSAGE 0
#define EVENT_SCHEDULER_NOTIFY 1
#define EVENT_DISCORD_VOICE_STATE 2
#define EVENT_HTTP_RESPONSE 3

#define PLATFORM_TWITCH 1
#define PLATFORM_DISCORD 2
#define PLATFORM_SLACK 3
#define PLATFORM_MIXER 4
#define PLATFORM_YOUTUBE 5
#define PLATFORM_CURSE 6
#define PLATFORM_API 7

#define HTTP_GET 0
#define HTTP_POST 1
#define HTTP_PUT 2
#define HTTP_DELETE 3

#define DISPLAYNAME_USER 0
#define DISPLAYNAME_CHANNEL 1

/* A standard UUID */
struct v1x1_uuid {
    uint64_t high;
    uint64_t low;
} __attribute__((__packed__));

/* A buffer.  Used for strings and the like. */
struct v1x1_buffer {
    int32_t length;
    void *buf;
} __attribute__((__packed__));

/* A tenant is a grouping of channel_groups */
struct v1x1_tenant {
    struct v1x1_uuid id;
    struct v1x1_buffer display_name;
} __attribute__((__packed__));

/* A channel_group is a grouping of channels on a given platform */
struct v1x1_channel_group {
    struct v1x1_buffer id;
    struct v1x1_buffer display_name;
    uint8_t platform;
    struct v1x1_tenant tenant;
} __attribute__((__packed__));

/* A channel is a named location where messages are broadcast and received */
struct v1x1_channel {
    struct v1x1_buffer id;
    struct v1x1_buffer display_name;
    struct v1x1_channel_group channel_group;
} __attribute__((__packed__));

/* A global_user is a grouping of users that belong to the same person */
struct v1x1_global_user {
    struct v1x1_uuid id;
} __attribute__((__packed__));

/* A user is an actor on a given platform */
struct v1x1_user {
    struct v1x1_buffer id;
    struct v1x1_buffer display_name;
    uint8_t platform;
    struct v1x1_global_user global_user;
} __attribute__((__packed__));

/* A permission is a string that represents a privilege granted */
struct v1x1_permission {
    struct v1x1_buffer node;
} __attribute__((__packed__));

/* A permission_set is a list of permissions granted to a user on a channel */
struct v1x1_permission_set {
    int32_t length;
    struct v1x1_permission *permissions;
} __attribute__((__packed__));

/* A message is a byte sequence sent from a user to a channel */
struct v1x1_message {
    struct v1x1_channel channel;
    struct v1x1_user sender;
    struct v1x1_buffer text;
    struct v1x1_permission_set permissions;
} __attribute__((__packed__));

/* An event_message is an event that is fired when a message is received */
struct v1x1_event_message {
    struct v1x1_message message;
} __attribute__((__packed__));

/* An event_scheduler_notify is an event that is triggered by v1x1_schedule_once */
struct v1x1_event_scheduler_notify {
    struct v1x1_buffer payload;
} __attribute__((__packed__));

/* A discord_voice_state is the state of a user's voice connection on the discord platform */
struct v1x1_discord_voice_state {
    struct v1x1_buffer guild_id;
    struct v1x1_buffer channel_id;
    struct v1x1_buffer user_id;
    struct v1x1_buffer session_id;
    uint8_t deaf;
    uint8_t mute;
    uint8_t self_deaf;
    uint8_t self_mute;
    uint8_t suppress;
} __attribute__((__packed__));

/* An event_discord_voice_state is an event sent when a user's discord_voice_state changes */
struct v1x1_event_discord_voice_state {
    struct v1x1_discord_voice_state old_voice_state;
    struct v1x1_discord_voice_state new_voice_state;
} __attribute__((__packed__));

/* An http_header is a struct describing a single HTTP header */
struct v1x1_http_header {
    struct v1x1_buffer name;
    struct v1x1_buffer value;
} __attribute__((__packed__));

/* An event_http_response is an event sent when an http request completes */
struct v1x1_event_http_response {
    int32_t response_code;
    int32_t header_count;
    struct v1x1_http_header *headers;
    struct v1x1_buffer body;
    struct v1x1_buffer event_payload;
} __attribute__((__packed__));

/* An event is a struct describing the properties of a given change that is observed by v1x1 */
struct v1x1_event {
    uint8_t event_type;
    union {
        struct v1x1_event_message message_event;
        struct v1x1_event_scheduler_notify scheduler_notify_event;
        struct v1x1_event_discord_voice_state discord_voice_state_event;
        struct v1x1_event_http_response http_response_event;
    } data;
} __attribute__((__packed__));

/* A channel_group_spec is a struct describing the channels that belong to a channel_group */
struct v1x1_channel_group_spec {
    struct v1x1_channel_group channel_group;
    int32_t channel_count;
    struct v1x1_channel *channels;
} __attribute__((__packed__));

/* A tenant_spec is a struct describing the channel_groups that belong to a tenant */
struct v1x1_tenant_spec {
    struct v1x1_tenant tenant;
    int32_t channel_group_count;
    struct v1x1_channel_group_spec *channel_groups;
} __attribute__((__packed__));

/* An http_request is a struct describing an HTTP request */
struct v1x1_http_request {
    int32_t verb;
    struct v1x1_buffer uri;
    int32_t header_count;
    struct v1x1_http_header *headers;
    struct v1x1_buffer body;
    struct v1x1_buffer event_payload;
} __attribute__((__packed__));

/**
 * Get the size of the current event (in bytes)
 * @return size of the current event
 */
extern int32_t v1x1_event_size(void);

/**
 * Read the current event into memory.
 * @param ptr Location to read the current event into.
 * @param len Max length of event to read
 * @return non-zero on success
 */
extern int32_t v1x1_read_event(void *ptr, int len);

/**
 * Sends a chat message
 * @param channel Channel to send message to
 * @param message Text of message to send
 * @return non-zero on success
 */
extern int32_t v1x1_send_message(struct v1x1_channel *channel, struct v1x1_buffer *message);

/**
 * Clear a user's messages from a channel
 * @param channel Channel to clear messages from
 * @param user User whose messages we should clear
 * @param amount Number of messages to clear (if the platform supports it)
 * @param reason Reason for clearing messages
 * @return non-zero on success
 */
extern int32_t v1x1_purge(struct v1x1_channel *channel, struct v1x1_user *user, int32_t amount, struct v1x1_buffer *reason);

/**
 * Makes a user be quiet
 * @param channel Channel where user is not being quiet
 * @param user User to make quiet
 * @param length Duration (in seconds) to make user quiet for
 * @param reason Reason for making user quiet
 * @return non-zero on success
 */
extern int32_t v1x1_timeout(struct v1x1_channel *channel, struct v1x1_user *user, int32_t length, struct v1x1_buffer *reason);

/**
 * Stop making a user be quiet
 * @param channel Channel where the user has been made to be quiet
 * @param user User who has been made to be quiet
 * @return non-zero on success
 */
extern int32_t v1x1_untimeout(struct v1x1_channel *channel, struct v1x1_user *user);

/**
 * Temporarily remove a user from a channel
 * @param channel Channel from which to remove the user
 * @param user User to be removed
 * @param reason Reason for removing the user
 * @return non-zero on success
 */
extern int32_t v1x1_kick(struct v1x1_channel *channel, struct v1x1_user *user, struct v1x1_buffer *reason);

/**
 * Less temporarily remove a user from a channel
 * @param channel Channel from which to remove the user
 * @param user User to be removed
 * @param length Duration (in seconds) before the user can come back, 0 for indefinite (if supported)
 * @param reason Reason for removing the user
 * @return non-zero on success
 */
extern int32_t v1x1_ban(struct v1x1_channel *channel, struct v1x1_user *user, int32_t length, struct v1x1_buffer *reason);

/**
 * Punish user in the minimal way supported by the platform
 * @param channel Channel where the user should be punished
 * @param user User to be punished
 * @param length Duration (in seconds) to punish the user for (if supported)
 * @param reason Reason for punishing the user
 * @return non-zero on success
 */
extern int32_t v1x1_punish(struct v1x1_channel *channel, struct v1x1_user *user, int32_t length, struct v1x1_buffer *reason);

/**
 * Generates a SCHEDULER_NOTIFY event after a given duration
 * @param minutes Duration (in minutes) to wait before delivering the SCHEDULER_NOTIFY event
 * @param payload Payload to send in the SCHEDULER_NOTIFY event
 * @return non-zero on success
 */
extern int32_t v1x1_schedule_once(int32_t minutes, struct v1x1_buffer *payload);

/**
 * Writes a value to the key-value store
 * @param key Location to write the value
 * @param val Value to write
 * @return non-zero on success
 */
extern int32_t v1x1_kvstore_write(struct v1x1_buffer *key, struct v1x1_buffer *val);

/**
 * Checks if a value exists in the key-value store at a given key
 * @param key Location to look for value
 * @return non-zero if key has a value
 */
extern int32_t v1x1_kvstore_has_key(struct v1x1_buffer *key);

/**
 * Get the length of a value at a given key in the key-value store
 * @param key Location to look for value
 * @return Length of value, -1 if key does have a value
 */
extern int32_t v1x1_kvstore_length(struct v1x1_buffer *key);

/**
 * Reads a value from the key-value store
 * @param key Location to read the value
 * @param val Buffer to write the value to
 * @return non-zero on success
 */
extern int32_t v1x1_kvstore_read(struct v1x1_buffer *key, struct v1x1_buffer *val);

/**
 * Deletes a value from the key-value store
 * @param key Location to delete
 * @return non-zero on success
 */
extern int32_t v1x1_kvstore_delete(struct v1x1_buffer *key);

/**
 * Logs a message
 * @param message Message to be logged
 * @return non-zero on success
 */
extern int32_t v1x1_log(struct v1x1_buffer *message);

/**
 * Gets the size of the current tenant spec (in bytes)
 * @return size of tenant spec
 */
extern int32_t v1x1_tenant_spec_size(void);

/**
 * Gets the current tenant spec struct
 * @param tenant_spec Struct to be filled
 * @param len Length of allocated struct
 * @return non-zero on success
 */
extern int32_t v1x1_get_tenant_spec(struct v1x1_tenant_spec *tenant_spec, int32_t len);

/**
 * Makes an HTTP request.  Data will be returned via event
 * to a random instance of your WebAssembly script.
 * @param request Struct containing request data
 * @return non-zero on success
 */
extern int32_t v1x1_http(struct v1x1_http_request *request);

/**
 * Gets a display_name for an entity
 * @param display_name_type Type of entity
 * @param platform Platform of entity
 * @param id Buffer containing ID of entity
 * @param display_name Buffer containing room to write display_name
 * @return non-zero on success
 */
extern int32_t v1x1_get_display_name(int32_t display_name_type, int32_t platform, struct v1x1_buffer *id, struct v1x1_buffer *display_name);

/**
 * Makes a v1x1_buffer from a length and pointer
 * @param length Length of buffer
 * @param data Pointer to data
 * @return Built v1x1_buffer
 */
struct v1x1_buffer v1x1_mkbuffer(int32_t length, char *data);

/**
 * Makes a v1x1_buffer from a C string
 * @param str C string
 * @return Built v1x1_buffer
 */
struct v1x1_buffer v1x1_mkstrbuffer(char *str);

/**
 * Sends a C string message to a channel
 * @param channel Channel to send message to.
 * @param message C string containing message.
 * @return (see v1x1_send_message)
 */
int32_t v1x1_send_string_message(struct v1x1_channel *channel, char *message);

/**
 * Sends a message to a channel with a printf format
 * @param channel Channel to send message to.
 * @param format Format (see printf)
 * @param ... format arguments (see printf)
 * @return (see v1x1_send_message)
 */
int32_t v1x1_printf_message(struct v1x1_channel *channel, char *format, ...);
#ifdef __cplusplus
}
#endif
#endif

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

struct v1x1_buffer v1x1_mkbuffer(int32_t length, char *data) {
  struct v1x1_buffer buffer = {
    length, data
  };
  return buffer;
}

struct v1x1_buffer v1x1_mkstrbuffer(char *str) {
  return v1x1_mkbuffer(strlen(str), str);
}

int32_t v1x1_send_string_message(struct v1x1_channel *channel, char *message) {
  struct v1x1_buffer buffer = v1x1_mkstrbuffer(message);
  return v1x1_send_message(channel, &buffer);
}

int32_t v1x1_printf_message(struct v1x1_channel *channel, char *format, ...) {
  char buf[4096];
  va_list args;
  va_start(args, format);
  vsnprintf(buf, 4096, format, args);
  int32_t ret = v1x1_send_string_message(channel, buf);
  va_end(args);
  return ret;
}

#include <stdlib.h>

void do_log(char *message) {
  struct v1x1_buffer buffer = v1x1_mkstrbuffer(message);
  v1x1_log(&buffer);
}

void do_logf(char *format, ...) {
  char buf[4096];
  va_list args;
  va_start(args, format);
  vsnprintf(buf, 4096, format, args);
  do_log(buf);
  va_end(args);
};

WASM_EXPORT
void event_handler(void) {
  int event_size = v1x1_event_size();
  if(event_size < 0)
    return;
  struct v1x1_event *evt = malloc(event_size);
  v1x1_read_event(evt, event_size);
  if(evt->event_type == EVENT_MESSAGE) {
    struct v1x1_message *msg = &evt->data.message_event.message;
    if(!strcmp(msg->text.buf, "!np") || !strcmp(msg->text.buf, "!nowplaying") || !strcmp(msg->text.buf, "!playing") || !strcmp(msg->text.buf, "!song")) {
      volatile struct v1x1_http_request req = {0};
      req.uri = v1x1_mkstrbuffer(DRASKIA_NP_URL);
      v1x1_http(&req);
    }
  } else if(evt->event_type == EVENT_HTTP_RESPONSE) {
    struct v1x1_channel channel = {
      .id = v1x1_mkstrbuffer("50996205:main"),
      .channel_group = {
        .id = v1x1_mkstrbuffer("50996205"),
        .platform = PLATFORM_TWITCH
      }
    };
    v1x1_printf_message(&channel, "Draskia is %s", evt->data.http_response_event.body.buf);
  }
  free(evt);
}