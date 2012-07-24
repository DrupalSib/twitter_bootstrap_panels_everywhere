<?php
/**
 * @file
 * Template for a twitter bootstrap site template layout.
 */
?>
<header id="navbar" role="banner" class="navbar navbar-fixed-top">
  <div class="navbar-inner">
    <div class="container">
      <!-- .btn-navbar is used as the toggle for collapsed navbar content -->
      <a class="btn btn-navbar" data-toggle="collapse" data-target=".nav-collapse">
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
      </a>

      <?php print render($content['sticky_bar_logo']); ?>

      <div class="nav-collapse">
        <nav role="navigation">
          <?php print render($content['sticky_bar_navigation_left']); ?>
          <?php print render($content['sticky_bar_navigation_right']); ?>
        </nav>
      </div>


    </div>
  </div>
</header>

<div class="container">

  <?php if (!empty($content['header'])): ?>
    <header role="banner" id="page-header">
      <?php print render($content['header']); ?>
    </header> <!-- /#header -->
  <?php endif; ?>

  <div class="row">

    <?php if ($content['sidebar_first']): ?>
      <aside class="span3" role="complementary">
        <?php print render($content['sidebar_first']); ?>
      </aside>  <!-- /#sidebar-first -->
    <?php endif; ?>

    <section class="<?php print $content_region_class; ?>">
      <?php if ($content['highlighted']): ?>
        <div class="highlighted hero-unit"><?php print render($content['highlighted']); ?></div>
      <?php endif; ?>
      <a id="main-content"></a>
      <?php print render($content['content_top']); ?>
      <?php if ($content['help']): ?>
        <div class="well"><?php print render($content['help']); ?></div>
      <?php endif; ?>
      <?php print render($content['content']); ?>
    </section>

    <?php if (!empty($content['sidebar_second'])): ?>
      <aside class="span3" role="complementary">
        <?php print render($content['sidebar_second']); ?>
      </aside>  <!-- /#sidebar-second -->
    <?php endif; ?>

  </div>
  <footer class="footer container">
    <?php print render($content['footer']); ?>
  </footer>
</div>
