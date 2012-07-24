<?php
/**
 * @file
 * Template for a page_site_name pane.
 */
?>

<?php if (!empty($content)): ?>
  <hgroup id="site-name-slogan">
    <h1>
      <a href="<?php print url(); ?>" title="<?php print t('Home'); ?>" class="brand"><?php print check_plain($content); ?></a>
    </h1>
  </hgroup>
<?php endif; ?>
