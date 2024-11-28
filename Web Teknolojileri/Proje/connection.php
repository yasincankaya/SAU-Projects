<?php 
    $servername = "sql101.epizy.com";
    $username = "epiz_34255831";
    $password = "DK1dn0zAC5";
    $db_name = "epiz_34255831_database1";  
    $conn = new mysqli($servername, $username, $password, $db_name, 3306);
    if($conn->connect_error){
        die("Connection failed".$conn->connect_error);
    }
    echo " ";
    
    ?>