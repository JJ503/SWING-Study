<html>
	<body>
	<?
	@session_start();
	$id = $_POST['name'];
	$pw = $_POST['password'];
	
	$con = mysqli_connect("localhost", "root", "autoset", "login") or die ("connect error");
	
	$check_id = "select * from login where id like '$id'";
	$number1 = $con->query($check_id);
	
	$check_pw = "select * from login where pw like '$pw'";
	$number2 = $con->query($check_pw);
	
	if ($number1 -> num_rows == 1 and $number2 -> num_rows == 1)
	{
		$_SESSION['id'] = $id;
		$_SESSION['pw'] = $pw;
		header('Location: ./index.php');
		exit;
	}
	
	else
	{
		echo "<script> alert ('아이디 혹은 패스워드가 잘못 되었습니다'); history.back(); </script>";
		exit;
	}
	?>
	</body>
</html>