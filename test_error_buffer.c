#include <stdio.h>
#define PIN_ERR_IS_ERR(ebufp) (__pin_err_is_err(PIN_FILE_SOURCE_ID, PIN_SOURCE_LINE_NUMBER, PIN_FUNCTION_NAME, ebufp))
	
	int32 __pin_err_is_err(const char* file_name, pin_err_line_no_t  line_number, const char* function_name, pin_errbuf_t* ebufp) {

	int32 ebufp_ret_val = 0;

	if (ebufp != (pin_errbuf_t *)0) {
		if ((ebufp)->pin_err != PIN_ERR_NONE) {
			ebufp_ret_val = (ebufp)->pin_err;
		}
	} else {
		ebufp_ret_val = fprintf(stderr, "\n*** Error buffer not initialized in %s (%s:%d) ***\n",__FUNC__, __FILE__, __LINE__); 
	}
	return ebufp_ret_val;

}


int main() {
pin_errbuf_t	 *ebufp = NULL;
if (PIN_ERR_IS_ERR(ebufp)) {
 ebufp->reserved = 3;
}

return 0;
}
