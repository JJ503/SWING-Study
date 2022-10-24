<html>
	<body>

	<?php
		$con = mysqli_connect("localhost", "root", "autoset", "login") or die ("connect error");
		$new_id = $_POST['new_id'];
		$new_pw = $_POST['new_pw'];
		
		$overlap = "select * from login where id like '$new_id'";
		$number = $con->query($overlap);
		if ($number -> num_rows == 1)
		{
			echo "<script> alert ('사용할 수 없는 아이디입니다.'); history.back(-1); </script>";
			exit();
		}
		
		else
		{
			$join = "insert into login values ('{$new_id}', '{$new_pw}')";
			mysqli_query($con, $join);
			header('Location: index.php');
			exit();
		}
	?>
	</body>
</html>