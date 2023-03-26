/* Network ID */
#define DEVICE_ID 0
#define NUMBER_OF_DEVICES 2

/* Debug */
#define NDEBUG

/* Features */
//#define ENABLE_MEASURE
#if !defined(DEVICE_TYPE)
	#if DEVICE_ID == 0
		#if !defined(ENABLE_GATEWAY)
			#define ENABLE_GATEWAY
		#endif
	#else
		#if !defined(ENABLE_MEASURE)
			#define ENABLE_MEASURE
		#endif
	#endif
#endif
//#define ENABLE_LED
//#define ENABLE_COM_OUTPUT
//#define ENABLE_OLED_OUTPUT
#if defined(ENABLE_MEASURE)
//	#define ENABLE_SD_CARD
#endif
#if !defined(ENABLE_GATEWAY)
//	#define ENABLE_SLEEP
//	#define ENABLE_CLOCK CLOCK_DS3231
#endif
//#define ENABLE_BATTERY_GAUGE BATTERY_GAUGE_DFROBOT
//#define ENABLE_DALLAS
//#define ENABLE_BME280
//#define ENABLE_LTR390

/* Software Parameters */
#define WIFI_SSID "TP-Link_9006"
#define WIFI_PASS "52057294"
#define HTTP_UPLOAD_LENGTH 256
#define HTTP_UPLOAD_FORMAT \
        "http://45.120.0.201:2345/REST/upload?device=%1$u&serial=%2$u&time=%3$s"\
        "&battery_voltage=%4$.2F&battery_percentage=%5$.2F"\
        "&temperature=%6$.1F&pressure=%7$.1F&humidity=%8$.1F"
#define HTTP_AUTHORIZATION_TYPE "Basic"
#define HTTP_AUTHORIZATION_CODE "THISISTOKEN"
#define NTP_SERVER "stdtime.gov.hk"
#define SECRET_KEY "This is secret!"

#define NTP_INTERVAL 654321UL /* milliseconds */
#define SYNCHONIZE_INTERVAL 7654321UL /* milliseconds */
#define RESEND_TIMES 3
#define ACK_TIMEOUT 1000UL /* milliseconds */
#define SEND_INTERVAL 6000UL /* milliseconds */ /* MUST: > ACK_TIMEOUT * RESEND_TIMES */
#define MEASURE_INTERVAL 60000UL /* milliseconds */ /* MUST: > SEND_INTERVAL */
#define ROUTER_TOPOLOGY {}

/* Hardware Parameters */
#if !defined(ENABLE_GATEWAY)
	#define CPU_FREQUENCY 20 /* MUST: >= 20 for LoRa, and >= 80 for WiFi */
#endif
#if defined(ENABLE_GATEWAY) && !(CPU_FREQUENCY >= 80)
	#undef CPU_FREQUENCY
	#define CPU_FREQUENCY 80
#endif
#if !(CPU_FREQUENCY >= 20)
	#undef CPU_FREQUENCY
	#define CPU_FREQUENCY 20
#endif
#define COM_BAUD 115200
#define DALLAS_PIN 3
