#include "http_server.h"

int main()
{
	struct evhttp *http_server = NULL;
	short http_port = 8081;
	char *http_addr = "0.0.0.0";
	
	//初始化
	event_init();
	//启动http服务端
	http_server = evhttp_start(http_addr,http_port);
	if(http_server == NULL)
	{
		printf("====line:%d,%s\n",__LINE__,"http server start failed.");
		return -1;
	}
	
	//设置请求超时时间(s)
	evhttp_set_timeout(http_server,5);
	//设置事件处理函数，evhttp_set_cb针对每一个事件(请求)注册一个处理函数，
	//区别于evhttp_set_gencb函数，是对所有请求设置一个统一的处理函数
	evhttp_set_cb(http_server,"/me/testpost", http_handler_testpost_msg, NULL);
	evhttp_set_cb(http_server,"/me/testget", http_handler_testget_msg, NULL);

	//循环监听
	event_dispatch();
	//实际上不会释放，代码不会运行到这一步
	evhttp_free(http_server);
		
	return 0;
}