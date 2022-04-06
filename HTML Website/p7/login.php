<!DOCTYPE html>
<html>
<head>
    <title>Login Page</title>
    <link rel="stylesheet" href="css/logincss.css">
</head>
<body>
    <div id="form">
        <form action="process.php" method="POST">
            <p>
                <label>Username</label>
                <input id="username" name="username" type="text">
            </p>
            <p>
                <label>Password</label>
                <input id="password" name="password" type="text">
            </p>
            <p>
                <input type="submit" id="button" value="login">
            </p>
        </form>
    </div>
    
</body>
</html>