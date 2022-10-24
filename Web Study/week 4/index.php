<?
    @session_start();
    
    if (isset($_SESSION['id']) and isset($_SESSION['pw'])){
		echo "ID : {$_SESSION['id']}<br>";
		echo "PW : {$_SESSION['pw']}</p>";
		
		echo "<a href = 'logout.php'> ==LOGOUT== </a>";
    }

    else{
		header('Location: login.php');
	}
?>