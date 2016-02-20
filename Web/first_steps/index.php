<?php 
error_reporting(E_ALL);

include("config.php");
?>

<link rel="stylesheets" type="text/css" href="css/style.css" />
<div class="all_block">
<?php
switch ($_GET['p']) {
	case "index":
		<<TXT

		<div class="index_hellow">Weclome</div>



		TXT;
		break;
	case "reg":
		include("page/reg_page.php");
		break;
	default:
		echo<<TXT

		<div class="index_hellow">Weclome</div>



		TXT;
		break;
}?>


</div>