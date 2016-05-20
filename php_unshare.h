/* __header_here__ */

#ifndef PHP_UNSHARE_H
#define PHP_UNSHARE_H

extern zend_module_entry unshare_module_entry;
#define phpext_unshare_ptr &unshare_module_entry

#define PHP_UNSHARE_VERSION "0.1.0"

#ifdef PHP_WIN32
#	define PHP_UNSHARE_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_UNSHARE_API __attribute__ ((visibility("default")))
#else
#	define PHP_UNSHARE_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

/* 
  	Declare any global variables you may need between the BEGIN
	and END macros here:     

ZEND_BEGIN_MODULE_GLOBALS(unshare)
	long  global_value;
	char *global_string;
ZEND_END_MODULE_GLOBALS(unshare)
*/

/* In every utility function you add that needs to use variables 
   in php_unshare_globals, call TSRMLS_FETCH(); after declaring other 
   variables used by that function, or better yet, pass in TSRMLS_CC
   after the last function argument and declare your utility function
   with TSRMLS_DC after the last declared argument.  Always refer to
   the globals in your function as UNSHARE_G(variable).  You are 
   encouraged to rename these macros something shorter, see
   examples in any other php module directory.
*/

#ifdef ZTS
#define UNSHARE_G(v) TSRMG(unshare_globals_id, zend_unshare_globals *, v)
#else
#define UNSHARE_G(v) (unshare_globals.v)
#endif

#endif	/* PHP_UNSHARE_H */

/* __footer_here__ */
