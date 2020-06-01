all:
	gcc logger.c -g -fPIC -shared -o liblogger.so
	gcc -g -o test_loger test_loger.c -I./ -L./ -llogger
