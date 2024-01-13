#include <stdio.h>
#include <stdlib.h>
#include "/media/psf/Home/Desktop/OEL/headers/fetch_header.h"
#include "/media/psf/Home/Desktop/OEL/headers/dataprocess_header.h"
#include "/media/psf/Home/Desktop/OEL/headers/report_header.h"
#include "/media/psf/Home/Desktop/OEL/headers/resultstruct_header.h"

int main (int args, char *argv[]) {

	//printf("args %d\n", args);
	//printf("%s\n", argv[1]);
	if (*argv[1] == '1' ) {
		printf("1 evaluated\n");
		fetch_data();
	}
	else if (*argv[1] == '2' ) {
		printf("2 evaluated\n");
		process_data();
		
	}
	else if (*argv[1] == '3' ) {
		printf("3 evaluated\n");
		struct Result *re = report_data();
		int mint = re->min;
		int s;
		if (mint < 45) {
			s = system("notify-send environment_is_very_cold");
			if (s== 0) { 
				printf("notified\n");
			}
			else {
				printf("system() error\n");
			}
		}
		
	}
	return 0;

}
