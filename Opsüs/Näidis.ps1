function valjasta {
    param ($nr, $param, $sisu)
    $fail = "$env:USERPROFILE\Desktop\tulemus.txt"
    $aeg = Get-Date -Format "HH:mm:ss.fff"
    if ($sisu -eq $null) {
        $rida = "$nr.    $aeg    ${param}: NULL"
        Write-Output $rida
        $rida | Out-File -FilePath $fail -Append
    } elseif ($sisu.GetType().Name -eq "Object[]") {
        $rida = "$nr.    $aeg    ${param}:"
        Write-Output $rida
        $rida | Out-File -FilePath $fail -Append
        $sisu | Out-File -FilePath $fail -Append
    } elseif ($sisu -is [System.Management.Automation.PSObject]) {
        $rida = "$nr.    $aeg    ${param}:"
        Write-Output $rida
        $rida | Out-File -FilePath $fail -Append
        $sisu | Format-Table -AutoSize | Out-String | Out-File -FilePath $fail -Append
    } else {
        $rida = "$nr.    $aeg    ${param}: $sisu"
        Write-Output $rida
        $rida | Out-File -FilePath $fail -Append
    }
}

function vahe {
    param (
        [string]$Text
    )
    $dashLine = "-" * 12
    $separator = "`n$dashLine $Text $dashLine"
    $separator | Out-File -FilePath "$env:USERPROFILE\Desktop\tulemus.txt" -Append
}



# Võrgu muutujad
$networkAdapter = Get-WmiObject Win32_NetworkAdapterConfiguration -Filter "IPEnabled='True'" |
    Select-Object -First 1
$adapterName = $networkAdapter.Description
$ipAddress = $networkAdapter.IPAddress[0]  
$subnetMask = $networkAdapter.IPSubnet[0]  
$gateway = $networkAdapter.DefaultIPGateway[0]  
$dhcpEnabled = $networkAdapter.DHCPEnabled
$macAddress = $networkAdapter.MACAddress

# Kuupäeva käsitlus
$driverDate = (Get-WmiObject Win32_VideoController).DriverDate
$cleanedDate = $driverDate.Substring(0, 8)
$formattedDate = $cleanedDate.Insert(4, ".").Insert(7, ".")

[int]$aegA = (Get-Date).Millisecond
valjasta 0 "ALGUS" ("Aeg: " + (Get-Date -Format "dddd MM/dd/yyyy HH:mm K") + " Teostaja: Jander Metsma")
vahe "Ülesanne 1"
valjasta 1 "Host" (hostname)
valjasta 2 "PS Versioon" ($PSVersionTable.PSVersion)
valjasta 3 "Win Versioon" ((Get-CimInstance Win32_OperatingSystem).Caption)
vahe "Ülesanne 2"
valjasta 4 "IP-aadress" $ipAddress
valjasta 5 "Võrgumask" $subnetMask
valjasta 6 "Gateway" $gateway
valjasta 7 "DHCP ON?" $dhcpEnabled
valjasta 8 "MAC-aadress" $macAddress
vahe "Ülesanne 3"
valjasta 9 "CPU" ((Get-CimInstance -ClassName Win32_Processor).name)
valjasta 10 "RAM" ((Get-CimInstance Win32_PhysicalMemory | Measure-Object -Property capacity -Sum).sum / 1gb)
vahe "Ülesanne 4"
valjasta 11 "GPU" ((Get-WmiObject Win32_VideoController).Name)
valjasta 12 "GPU-Driver V" ((Get-WmiObject Win32_VideoController).DriverVersion)
valjasta 13 "GPU-Driver D" ($formattedDate)
valjasta 14 "Res" ((Get-WmiObject Win32_VideoController).CurrentHorizontalResolution.ToString() + " x " + (Get-WmiObject Win32_VideoController).CurrentVerticalResolution.ToString())
vahe "Ülesanne 5"
valjasta 15 "Part. Tabel + Suurus" (
    Get-CimInstance Win32_DiskDrive | 
    Select-Object Caption, Partitions, @{Name="Size(GB)";Expression={[math]::round($_.Size / 1GB, 2)}}
)
Write-Output "`n"
valjasta 16 "C:/ Vaba" ([math]::Round(((Get-CimInstance Win32_LogicalDisk -Filter "DeviceID='C:'").FreeSpace / 1GB), 2))
vahe "Ülesanne 6"
valjasta 17 "PCI-siin" (
    Get-WmiObject -Class Win32_PnpSignedDriver | 
    Where-Object {$_.DeviceID -like "PCI*"} | 
    Select-Object Description, DriverVersion, Manufacturer | 
    Sort-Object Description | 
    Group-Object Description, DriverVersion, Manufacturer | 
    Select-Object @{Name="Description";Expression={$_.Name}}, 
                  @{Name="DriverVersion";Expression={$_.Group[0].DriverVersion}}, 
                  @{Name="Manufacturer";Expression={($_.Group[0].Manufacturer -join ", ")}} | 
    Format-Table -Property Description, DriverVersion, Manufacturer -AutoSize
)

vahe "Ülesanne 7"
valjasta 18 "Kasutajad" (Get-CimInstance Win32_UserAccount | Select-Object Name, Description, LocalAccount, Disabled)
vahe "Ülesanne 8"
valjasta 19 "Protsessid" ((Get-Process).Count)
vahe "Ülesanne 9"
valjasta 20 "10 Protsessi" (Get-Process | Sort-Object StartTime -Descending | Select-Object -First 10 Name, Id, StartTime | Format-Table -AutoSize)
vahe "Ülesanne 10"
valjasta 21 "Kuupäev ja kellaaeg" (Get-Date -Format "dddd, MM/dd/yyyy HH:mm:ss K")

[int]$aegL = (Get-Date).Millisecond
$ajakulu = ($aegL - $aegA)

valjasta 22 "TEHTUD" "$ajakulu`n`n"
