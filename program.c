#include <stdio.h>
#include <stdlib.h>
#include "/media/psf/Home/Desktop/OEL/headers/fetch_header.h"
#include "/media/psf/Home/Desktop/OEL/headers/dataprocess_header.h"
#include "/media/psf/Home/Desktop/OEL/headers/report_header.h"
#include "/media/psf/Home/Desktop/OEL/headers/resultstruct_header.h"

int main () {

    int opt = 0;
    struct Result *re;
    int mint;
    int s;
    while (opt != 4)  {
    	printf("1.fetch data\n2.process data\n3.report\n4.exit\n");
    	printf("selectopt: ");
    	scanf("%d", &opt);

    	switch (opt) {
    	case 1:
    		fetch_data();

    		break;
    	case 2:
    		process_data();
    		break;
    	case 3:
    		//report_data();
    		re = report_data();
		    mint = re->min;
		    if (mint < 45) {
			s = system("notify-send environment_is_very_cold");
			if (s== 0) { 
				printf("notified\n");
				}
			}
			else {
				printf("system() error\n");
		    break;

    		}
    	printf("report generated\n");
		}
	}	
}
