<?
	$text1 = "hi";
	$text2 = "hello";
?>
<html>
	<body>

		text1 : <?=$text1 ?> <br>
		text2 : <? echo $text2 ?> <br>
		
		<?
			echo "$text1 <br>";
			echo "hi";
		?>
		<?="bye" ?>
	</body>
</html>