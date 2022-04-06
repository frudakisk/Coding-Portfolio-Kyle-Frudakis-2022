<?php 
//values from login.php
$username = $_POST['username'];
$password = $_POST['password'];

//to prevent injections
$username = stripcslashes($username);
$password = stripcslashes($password);

//connecting the the server and getting stuff from database
$connection = new mysqli("localhost", "kfrudakis2018", "Unclesam10", "kfrudakis2018");


if($connection -> connect_error)
{
    echo "We have a problem";
}

$sql = "CREATE TABLE users (
    user_id INT(5) AUTO_INCREMENT PRIMARY KEY,
    username VARCHAR(50) NOT NULL,
    password VARCHAR(50) NOT NULL,
    unit VARCHAR(20) NULL,
    zipcode INT(5) NULL);";

    if ($connection -> query($sql) === TRUE) {
        echo "Table 'users' created";
    } else {
        echo "Error creating table ";
        echo $connection ->error;
    }

$connection->close();

    


//query the database for user

?>