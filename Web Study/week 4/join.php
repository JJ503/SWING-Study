<html>
<head>
	<title> join </title>
</head>
	
	<body>
	<meta http-equiv = "Content-Type" content = "text/html; charset=utf-8"/>
	<?php
        echo '<h1> &nbsp&nbsp&nbsp 회원가입 </h1>';
		echo '<form method = "POST" action = "join_db.php">';
		echo 'ID : <input type = "text" name = "new_id"> &nbsp&nbsp&nbsp <br><br>';
		echo 'PW : <input type = "password" name = "new_pw" <br><br><br>';
		echo '&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp<input type = "submit" value = "회원가입"> &nbsp&nbsp&nbsp&nbsp&nbsp&nbsp;';
		echo '<input type = "reset" value = "초기화"> <br><br>';
		echo '</form>';
	?>
	</body>
</html>