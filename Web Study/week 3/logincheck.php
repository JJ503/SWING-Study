<html>
	<body>
	<?
		@session_start();
		$id = $_POST['name'];
		$pw = $_POST['password'];
		
		if ($id == 'swing' and $pw == 'swing')
			{	
				$_session['id'] = $id;
				$_session['pw'] = $pw;
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