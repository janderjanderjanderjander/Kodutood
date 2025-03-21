$s = New-PSSession -ComputerName ARA-02, ARA-03, ARA-04, ARA-PS1, ARA-PS2, ARA-PS3
$test = foreach ($s in $s) {
Invoke-Command -Session $s -ScriptBlock {Get-CimInstance Win32_ComputerSystem | Select-Object Name | format-list *}
Invoke-Command -Session $s -ScriptBlock {Get-CimInstance Win32_OperatingSystem | Select-Object Caption | Format-List *}
Invoke-Command -Session $s -ScriptBlock {Get-CimInstance Win32_OperatingSystem | Select-Object Version | Format-List *}
Invoke-Command -Session $s -ScriptBlock {Get-CimInstance -ClassName Win32_ComputerSystem | Select-Object Model | Format-List *}
Invoke-Command -Session $s -ScriptBlock {Get-WmiObject -Class Win32_BIOS | Select-Object SMBIOSBIOSVersion | Format-List *}
"RAM : " + (Invoke-Command -Session $s -ScriptBlock {(Get-CimInstance Win32_PhysicalMemory | Measure-Object -Property capacity -Sum).sum /1gb}) + " GB"
"Moodulite arv suurus : " + (Invoke-Command -Session $s -ScriptBlock {((Get-WmiObject Win32_PhysicalMemoryArray | Measure-Object -Property MemoryDevices -sum).sum)}) + " x " + (Invoke-Command -Session $s -ScriptBlock {((Get-CimInstance Win32_PhysicalMemory | Measure-Object -Property capacity -Sum).sum /1gb) /((Get-WmiObject Win32_PhysicalMemoryArray | Measure-Object -Property MemoryDevices -sum).sum)}) + " GB"
Invoke-Command -Session $s -ScriptBlock {Get-WmiObject -Class Win32_PhysicalMemoryArray | Select-Object MemoryDevices | Format-List *}
}

$test | Out-file -FilePath 'C:\Users\Tu Deng\Desktop\tulemused.txt'
Get-Content 'C:\Users\Tu Deng\Desktop\tulemused.txt' | ? {$_ -ne ""} | Out-File 'C:\Users\Tu Deng\Desktop\uuedtulemused.txt'

Remove-PSSession $s