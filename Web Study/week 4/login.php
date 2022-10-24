<html>
	<body>
    <?php
        echo '<h1> &nbsp&nbsp&nbsp&nbsp&nbsp login </h1>';
		echo '<form method = "POST" action = "logincheck.php">';
		echo 'ID : <input type = "text" name = "name"> <br><br>';
		echo 'PW : <input type = "password" name = "password"> <br><br>';
		echo '&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp<input type = "submit" value = "Login"> &nbsp&nbsp&nbsp&nbsp&nbsp&nbsp;';
		echo '<input type = "reset" value = "초기화"> <br><br>';
		
		echo "&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp<a href = 'join.php'> ==회원가입== </a>";
		
		echo '</form>';
	?>
	</body>
</html>