<?
	@session_start();
	
	if (!empty($_session['id']) and !empty($_session['pw']))
	{
		echo "ID : {$_session['id']}<br>";
		echo "PW : {$_session['pw']}</p>";
		
		echo "<a href = 'logout.php'> ==LOGOUT== </a>";
	}
	
	else
		header('Location: ./login.php'); //로그인하러 가기
	
?>