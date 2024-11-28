<?php 
    include("connection.php");
    include("login.php");
?>
    
<html>
<head>
    <title>Login</title>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" type="text/css" href="style.css">
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.4.0/css/all.min.css"
		integrity="sha512-iecdLmaskl7CVkqkXNQ/ZH/XLlvWZOJyj7Yy7tcenmpD1ypASozpmT/E0iPtmFIB46ZmdtAc9eNBvH0H/ZpiBw=="
		crossorigin="anonymous" referrerpolicy="no-referrer" />
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.6.2/dist/css/bootstrap.min.css"
		integrity="sha384-xOolHFLEh07PJGoPkLv1IbcEPTNtaed2xpHsD9ESMhqIYd0nLMwNLD69Npy4HI+N" crossorigin="anonymous">
    <link rel="stylesheet" href="style.css">
</head>

<body>
    <div id="form">
        <div class="container">
            <div class="container mb-4">
                <h1 class="text-center">Giriş Yap</h1>
            </div>
            <div class="container">
                <form name="form" action="login.php" onsubmit="return isvalid()" method="POST">
                    <div class="form-group row">
                        <label class="col-12 col-md-3">Kullanıcı Adı:</label>
                        <div class="col-12 col-md-9">
                            <input type="email" id="user" name="user" class="form-control">
                        </div>
                    </div>
                    <div class="form-group row">
                        <label class="col-12 col-md-3">Şifre:</label>
                        <div class="col-12 col-md-9">
                            <input type="password" id="pass" name="pass" class="form-control">
                        </div>
                    </div>
                    <div class="row">
                        <div class="mx-auto col-10 col-md-8 col-lg-6">
                            <input type="submit" id="btn" value="Login" name="submit" class="btn btn-primary">
                        </div>
                    </div>
                </form>
            </div>
        </div>
    </div>

    <script>
        function isvalid() {
            var user = document.form.user.value;
            var pass = document.form.pass.value;
            if (user.length == "" && pass.length == "") {
                alert("Username and password field is empty!!!");
                return false;
            } else if (user.length == "") {
                alert("Username field is empty!!!");
                return false;
            } else if (pass.length == "") {
                alert("Password field is empty!!!");
                return false;
            }
        }
    </script>

    <script src="https://cdn.jsdelivr.net/npm/jquery@3.5.1/dist/jquery.slim.min.js"
        integrity="sha384-DfXdz2htPH0lsSSs5nCTpuj/zy4C+OGpamoFVy38MVBnE+IbbVYUew+OrCXaRkfj"
        crossorigin="anonymous"></script>
    <script src="https://cdn.jsdelivr.net/npm/popper.js@1.16.1/dist/umd/popper.min.js"
        integrity="sha384-9/reFTGAW83EW2RDu2S0VKaIzap3H66lZH81PoYlFhbGU+6BZp6G7niu735Sk7lN"
        crossorigin="anonymous"></script>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@4.6.2/dist/js/bootstrap.min.js"
        integrity="sha384-+sLIOodYLS7CIrQpBjl+C7nPvqq+FbNUBDunl/OZv93DB7Ln/533i8e/mZXLi/P+"
        crossorigin="anonymous"></script>
</body>

</html>
