<?php
    if(isset($_GET['CODE'])) {
        echo file_get_contents('code');
        die;
    }
    if(isset($_GET['code']))
               file_put_contents('code', $_GET['code']);
?>
<style>
    button {
        font-size: 10em;
    }
</style>
<center>
<from>
    <a href="/?code=11"><button>Start</button></a><br><br>
    <a href="/?code=10"><button>left</button></a>
    <a href="/?code=01"><button>right</button></a>
</form>
</center>
