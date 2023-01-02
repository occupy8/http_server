#include <stdio.h>
#include <stdlib.h>
#include <evhttp.h>
#include <event.h>
#include <string.h>

#include "event2/http.h"
#include "event2/event.h"
#include "event2/buffer.h"
#include "event2/bufferevent.h"
#include "event2/bufferevent_compat.h"
#include "event2/http_struct.h"
#include "event2/http_compat.h"
#include "event2/util.h"
#include "event2/listener.h"

#define BUF_MAX 1024*16

//处理post请求
void http_handler_testpost_msg(struct evhttp_request *req,void *arg);
//处理get请求
void http_handler_testget_msg(struct evhttp_request *req,void *arg);