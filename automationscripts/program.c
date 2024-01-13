#include <stdio.h>
#include <stdlib.h>
#include "/media/psf/Home/Desktop/OEL/headers/fetch_header.h"
#include "/media/psf/Home/Desktop/OEL/headers/dataprocess_header.h"
#include "/media/psf/Home/Desktop/OEL/headers/report_header.h"
#include "/media/psf/Home/Desktop/OEL/headers/resultstruct_header.h"

int main () {
    fetch_data();
    process_data();
    struct Result *re = report_data();
    int mint = re->min;
    int s;
    if (mint < 45) {
	s = system("notify-send environment_is_very_cold");
	if (s== 0) { 
		printf("notified\n");
		}
	}
	else {
		printf("system() error\n");

	}
}
