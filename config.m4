dnl $Id$
PHP_ARG_ENABLE(unshare, whether to enable unshare support, 
[  --enable-unshare          Enable unshare support])

if test "$PHP_UNSHARE" != "no"; then
  AC_DEFINE(HAVE_UNSHARE, 1, [ ])
  PHP_NEW_EXTENSION(unshare, unshare.c, $ext_shared)
fi
