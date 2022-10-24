<meta http-equiv = 'content-Type' content = 'text/html' charset = 'utf-8'>
<?
	session_start();
	
	echo "세션 시작~<p>";
	
	$_SESSION['userid'] = "jeonsu";
	$_SESSION['username'] = "정수";
	$_SESSION['time'] = time();
	
	echo "3개의 세션 변수 등룍 <br>";
	echo $_SESSION['userid'];
	echo $_SESSION['username'];
	echo $_SESSION['time'];
	
	session_destroy();
?>