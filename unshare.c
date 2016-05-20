
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_unshare.h"

#include "sched.h"

#include <unistd.h>
#include <sys/types.h>

/* {{{ proto int unshare(int arg)
   Return a string to confirm that the module is compiled in */
PHP_FUNCTION(unshare)
{
	long arg = 0;
	long unshare_flags = 0;
	int ret = 0;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &arg) == FAILURE) {
		return;
	}
	/*
	unshare_flags |= CLONE_NEWUSER;
	unshare_flags |= CLONE_NEWNET;
	*/
	unshare_flags = arg;
	ret = unshare(unshare_flags);

	RETURN_LONG(ret);

}
/* }}} */



#define REGISTER_UNSHARE_CONSTANT(__c) REGISTER_LONG_CONSTANT(#__c, __c, CONST_CS | CONST_PERSISTENT)

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(unshare)
{
	/* If you have INI entries, uncomment these lines 
	REGISTER_INI_ENTRIES();
	*/
	REGISTER_UNSHARE_CONSTANT(CLONE_VM);
	REGISTER_UNSHARE_CONSTANT(CLONE_FS);
	REGISTER_UNSHARE_CONSTANT(CLONE_FILES);
	REGISTER_UNSHARE_CONSTANT(CLONE_SIGHAND);
	REGISTER_UNSHARE_CONSTANT(CLONE_PTRACE);
	REGISTER_UNSHARE_CONSTANT(CLONE_VFORK);
	REGISTER_UNSHARE_CONSTANT(CLONE_PARENT);
	REGISTER_UNSHARE_CONSTANT(CLONE_THREAD);
	REGISTER_UNSHARE_CONSTANT(CLONE_NEWNS);
	REGISTER_UNSHARE_CONSTANT(CLONE_SYSVSEM);
	REGISTER_UNSHARE_CONSTANT(CLONE_SETTLS);
	REGISTER_UNSHARE_CONSTANT(CLONE_PARENT_SETTID);
	REGISTER_UNSHARE_CONSTANT(CLONE_CHILD_CLEARTID);
	REGISTER_UNSHARE_CONSTANT(CLONE_DETACHED);
	REGISTER_UNSHARE_CONSTANT(CLONE_UNTRACED);
	REGISTER_UNSHARE_CONSTANT(CLONE_CHILD_SETTID);
	REGISTER_UNSHARE_CONSTANT(CLONE_NEWUTS);
	REGISTER_UNSHARE_CONSTANT(CLONE_NEWIPC);
	REGISTER_UNSHARE_CONSTANT(CLONE_NEWUSER);
	REGISTER_UNSHARE_CONSTANT(CLONE_NEWPID);
	REGISTER_UNSHARE_CONSTANT(CLONE_NEWNET);
	REGISTER_UNSHARE_CONSTANT(CLONE_IO);
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(unshare)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(unshare)
{
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(unshare)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(unshare)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "unshare support", "enabled");
	php_info_print_table_end();

	DISPLAY_INI_ENTRIES();
}
/* }}} */

/* {{{ unshare_functions[]
 *
 * Every user visible function must have an entry in unshare_functions[].
 */
const zend_function_entry unshare_functions[] = {
	PHP_FE(unshare,	NULL)
	/* __function_entries_here__ */
	PHP_FE_END	/* Must be the last line in unshare_functions[] */
};
/* }}} */

/* {{{ unshare_module_entry
 */
zend_module_entry unshare_module_entry = {
	STANDARD_MODULE_HEADER,
	"unshare",
	unshare_functions,
	PHP_MINIT(unshare),
	PHP_MSHUTDOWN(unshare),
	PHP_RINIT(unshare),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(unshare),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(unshare),
	PHP_UNSHARE_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_UNSHARE
ZEND_GET_MODULE(unshare)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
