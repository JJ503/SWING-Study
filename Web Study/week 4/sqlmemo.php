<html>
	<body>
		<?
			$con = mysqli_connect("localhost", "root", "autoset", "memopage") or die ("connect error");
			$name = $_POST['name'];
			$pr = $_POST['pre'];
			
			$memo = "insert into memo values ('{$name}', '{$pr}')";
			mysqli_query($con, $memo);
			header('Location: memo.php');
		?>
	</body>
</html>