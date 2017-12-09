Param(  [String]$Att.
        [String]$Subj, 
        [String]$Body
     )

Function Send-Email
{
    Param(
            [Parameter(`
            Mandatory=$true)]
        [String]$To, 
            [Parameter(`
            Mandatory=$true)]
        [String]$From,
            [Parameter(`
            Mandatory=$true)]
        [String]$Password,
            [Parameter(`
            Mandatory=$true)]
        [String]$Subject,
            [Parameter(`
            Mandatory=$true)]
        [String]$Body,
            [Parameter(`
            Mandatory=$true)]
        [String]$Attachment
        )

try
{
    $Msg = New-Object System.Net.Mail.MailMessage($From, $To, $Subject, $Body)
    $Srv = "smtp.gmail.com"
    if ($Attachment -ne $null)
    {
        try
        {
            $Attachments = $Attachment -split ("\:\:");

            ForEach($val in $Attachments)
            {
                $Attch = New-Object System.Net.Mail.Attachment($val)
                $Msg.Attachments.Add($Attch)
            }
        }
        catch
        {
            exit 2;
        }

        $Client = New-Object Net.Mail.StmpClient($Srv, 587)
        $Client.EnableSsl = $true
        $Client.Credentials = New-Object System.Net.NetworkCredential($From.Split("@")[0], $Password);
        $Client.Send($Msg)
        Remove-Variable -Name Client
        Remove-Variable -Name Password
        exit 7;
    }
}
catch
{
    exit 3;
}
}

try
{
    Send-Email
        -attachment $Att
        -To "our.destination@email.address"
        -Body $Body
        -Subject $Subj
        -password "password"
        -From "Address of sender"
}
catch
{
    exit 4;
}