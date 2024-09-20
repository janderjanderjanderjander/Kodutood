$s  = New-PSSession -ComputerName 192.168.238.243 -Credential Jander_PC
$test = Invoke-Command -Session $s -ScriptBlock {
$Current_languages = Get-InstalledLanguage | Format-List *
$CurrentDate = Get-Date | Select-Object DateTime
$Current_languages
$CurrentDate
}
$test | Out-File -FilePath 'C:\Users\ThinkpadT490s\Desktop\Info.txt'
Invoke-Command -Session $s -ScriptBlock {Install-Language -Language fi-FI}
$test | Out-File -FilePath 'C:\Users\ThinkpadT490s\Desktop\Info2.txt'

Invoke-Command -Session $s -ScriptBlock {
$sleep = powercfg /query | Select-String "Sleep after" -Context 2,8
$screen_off = powercfg /query | Select-String "Turn off display after" -Context 2,8
}
$test = Invoke-Command -Session $s -ScriptBlock {
"Sleep time:"
[uint32](-split $sleep)[-7]
"Screen power off time:"
[uint32](-split $screen_off)[-7]
$CurrentDate = Get-Date | Select-Object DateTime
$CurrentDate
}
$test | Out-File -FilePath 'C:\Users\ThinkpadT490s\Desktop\Info3.txt'
Invoke-Command -Session $s -ScriptBlock {PowerCFG /Change standby-timeout-ac 20}
Invoke-Command -Session $s -ScriptBlock {PowerCFG /Change monitor-timeout-ac 600}

Invoke-Command -Session $s -ScriptBlock {
$sleep = powercfg /query | Select-String "Sleep after" -Context 2,8
$screen_off = powercfg /query | Select-String "Turn off display after" -Context 2,8
}
$test = Invoke-Command -Session $s -ScriptBlock {
"Sleep time:"
[uint32](-split $sleep)[-7]
"Screen power off time:"
[uint32](-split $screen_off)[-7]
$CurrentDate = Get-Date | Select-Object DateTime
$CurrentDate
}
$test | Out-File -FilePath 'C:\Users\ThinkpadT490s\Desktop\Info4.txt'




