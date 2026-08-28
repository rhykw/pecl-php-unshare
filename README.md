# [ARCHIVED] pecl-php-unshare

> [!WARNING]
> **[JA] このリポジトリはアーカイブされました**
> PHP 7.4 以降では、本体の PCNTL 拡張機能に [`pcntl_unshare()`](https://www.php.net/manual/ja/function.pcntl-unshare.php) が標準実装されたため、本拡張モジュールの開発およびメンテナンスは終了しました。今後は PHP 標準の `pcntl_unshare()` をご利用ください。
>
> **[EN] This repository is archived**
> Since PHP 7.4.0, [`pcntl_unshare()`](https://www.php.net/manual/en/function.pcntl-unshare.php) has been natively supported in the PCNTL extension. Therefore, this repository is archived and no longer maintained. Please use the native PHP function instead.

---

## 移行方法 / Migration

### PHP 7.4+

- **[JA]** PHP 7.4 以降では、PCNTL 拡張機能（`--enable-pcntl`）を有効にすることで標準関数として使用できます。
- **[EN]** In PHP 7.4 or later, you can use it as a native function by enabling the PCNTL extension (`--enable-pcntl`).

```php
// PECL extension (pecl-php-unshare) / PECL拡張版
// unshare(CLONE_NEWNET);

// PHP 7.4+ Native (PCNTL extension) / PHP 7.4+ 標準機能
pcntl_unshare(CLONE_NEWNET);
