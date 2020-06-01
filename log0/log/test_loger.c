#include "logger.h"

int main(int argc, char const *argv[])
{
	/* code */
	printf("start ......\n");

	/*basiConfig(1, "hell");*/

	logging.basiConfig(logging.DEBUG, "%(asctime)s-%(levelname)s-%(message)s");
	logging.debug("hello, world\n");
	logging.critical("something wrong happened\n");
	logging.warning("please call the stop function at the end\n");
	logging.error("something wrong happened\n");
	logging.disable(logging.ERROR);
	logging.critical("something wrong happened\n");
	logging.debug("hello, world\n");
	logging.stop();
	printf("end ......\n");
	return 0;
}
