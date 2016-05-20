--TEST--
Check for unshare presence
--SKIPIF--
<?php if (!extension_loaded("unshare")) print "skip"; ?>
--FILE--
<?php 
echo "unshare extension is available";
?>
--EXPECT--
unshare extension is available
