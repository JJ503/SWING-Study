<?php
	$num = $_GET['num'];
	
	switch($num) {
	case 1 :
		echo "num = 1";
		break;
	case 2 :
		echo "num = 2";
		break;
	default : 
		echo "num != 1, 2";
		break;
	}
?>