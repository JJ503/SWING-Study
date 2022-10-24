<html>
<head>
	<title> memo </title>
</head>

	<body>
	<?
		echo '<form method = "POST" action = "sqlmemo.php">';
		
		echo '이름 : <input type = "text" name = "name"> <br><br>';
		echo '메모 : <textarea rows = "10" cols = "20" name = "pre"> memo </textarea> <br><br>';
		echo '<input type = "submit" value = "submit">';

		echo '</form>';
	?>
	</body>
</html>