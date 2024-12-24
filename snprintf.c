/*
 * snprintf
 *
 * This function is implemented to ensure string termination
 * We are using this function to satisfy Fortify String
 * termination errors
 */
int snprintf (
	char *buffer, 
	size_t bufsz, 
	const char *format, 
	...)
{
	va_list vlist;
	int formatted_length = 0;

	// Validate input pointers
	if (buffer == NULL || format == NULL) {
        	return -1;
    	}

	// Validate buffer size
	if (bufsz == 0 || bufsz > RSIZE_MAX) {
        	return -1;
    	}

	// Initialize buffer to ensure null-termination
	buffer[0] = '\0';

	va_start(vlist, format);
	formatted_length = vsnprintf(buffer, bufsz, format, vlist);
	va_end(vlist);

	// Handle encoding errors
	if (formatted_length < 0) {
		buffer[0] = '\0';
		return -1;
	}

	// Check for truncation
	if (formatted_length >= bufsz) {
		buffer[bufsz - 1] = '\0'; // Ensure null-termination
	}

	return formatted_length;
}
