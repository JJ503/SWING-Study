<html>
	<body>
	<?php
		@session_start();
        @session_destroy();
		echo "<script> alert('세션이 비어있기에 로그인 페이지로 이동합니다')";
		header('Location: index.php');
	?>
	</body>
</html>