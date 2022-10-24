<html>
<head>
	<title> memofin </title>
</head>

	<body>
		<meta http-equiv = "Content-Type" content = "text/html; charset = utf-8"/>
		<?
			$con = mysqli_connect("localhost", "root", "autoset", "memopage") or die ("connect error");
			
			$query = "select * from memo;";
			$result = mysqli_query($con, $query) or die ("query error");
			
			$number = 1;
		?>
		
		<table width = "600" border = "1" cellpadding = "10">
			<tr alighn = "center">
				<td bdclor = "#cccccc"> 번호 </td>
				<td bdclor = "#cccccc"> 이름 </td>
				<td bdclor = "#cccccc"> 메모 </td>
			</tr>
			
		<?
			while ($row = mysqli_fetch_array($result))
			{
				echo "
						<tr>
						<td> $number </td>
						<td> $row[name] </td>
						<td> $row[memo] </td>
						</tr>
					";
				$number++;
			}
			mysqli_close($con);
		?>
	</body>
</html>