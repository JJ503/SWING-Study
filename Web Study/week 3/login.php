<html>
	<body>
	<?
		echo "<h1> login </h1>";
	
		echo '<form method = "POST" action = "logincheck.php">';
	
		echo 'ID : <input type = "text" name = "name"> <br><br>';
		echo 'PW : <input type = "password" name = "password"> <br><br>';
		echo '<input type = "submit" value = "Login"> &nbsp;';
		echo '<input type = "reset" value = "reset">';
	
		echo "</form>";
	?>
	</body>
</html>