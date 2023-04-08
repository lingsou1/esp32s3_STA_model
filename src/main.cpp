/*
接线说明:无

程序说明:开发板连接WiFi

注意事项:无

函数示例:无

作者:灵首

时间:2023_3_8

*/

#include <Arduino.h>
#include <WiFi.h>
#include <WiFiMulti.h>

/*
# brief WiFi连接函数
# param ssid:连接的WiFi的名称
# param password:连接的WiFi的密码
# retval 无
*/
void WiFi_Connect(const char* ssid,const char* password)
{
	WiFi.begin(ssid, password);
	while (WiFi.status() != WL_CONNECTED)
	{ //这里是阻塞程序，直到连接成功
		delay(300);
		Serial.print(".");
	}
}


void setup() {
  Serial.begin(115200);   //打开串口

  WiFi_Connect("LINGSOU234","12345678");    //连接指定WiFi

  // put your setup code here, to run once:
}

void loop() {
  Serial.println("\nlocao ip address:  ");
  Serial.print(WiFi.localIP());   //输出开发板所分配的IP地址
  delay(1000);
  // put your main code here, to run repeatedly:
}