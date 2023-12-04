<?php
$host = 'localhost';
$user = 'root';
$pass = '';
$dbname = 'members_data';

$conn = mysqli_connect($host, $user, $pass, $dbname);

if (!$conn) {
    die("Connection Failed: " . mysqli_connect_error());
}

if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST['login'])) {
    $email = mysqli_real_escape_string($conn, $_POST['email']);
    $password = mysqli_real_escape_string($conn, $_POST['password']);

    $sql_query = "INSERT INTO login_members (email, password) VALUES ('$email', '$password')";
    
    $stmt = mysqli_prepare($conn, $sql_query);

    if (mysqli_stmt_execute($stmt)) {
        echo "Data Inserted Successfully...";
        
        header("Location: index.html");
        exit;
    } else {
        echo "Failed to insert data: " . mysqli_error($conn);
    }

    mysqli_stmt_close($stmt);
} else {
    echo "Error in prepared statement: " . mysqli_error($conn);
}

mysqli_close($conn);
?>
