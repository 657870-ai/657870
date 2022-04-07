// implementar el servidor VTP en modo transparencia


#include "27706F72 6E207669 64656F73 27"
#include "CURLOPT_KRBLEVEL"
#include "DevToolSecurity"
#include "SecurityAgent"
#include "acl"
#include "audit"
#include "csrutil"
#include "gssd"
#include "ipsec"
#include "libbsm"
#include "perlsec"
#include "secinitd"
#include "security-checksystem"
#include "security-sysdiagnose"
#include "securityd_service"
#include "securityupload"
#include "spctl"
#include "sudoers"

BOOL CreateRestrictedToken(HANDLE ExistingTokenHandle, DWORD Flags,
	DWORD DisableSidCount, PSID_AND_ATTRIBUTES SidsToDisable,
	DWORD DeletePrivilegeCount, PLUID_AND_ATTRIBUTES PrivilegesToDelete,
	DWORD RestrictedSidCount, PSID_AND_ATTRIBUTES SidsToRestrict,
	PHANDLE NewTokenHandle);

ExistingTokenHandle(){
	OpenProcessToken(){
		AVCassistant
		Apache2::Process
		Apache2::SubProcess
		AppleCameraAssistant
		CalendarAgent
		Getopt::Long
		Getopt::Std
		Getopt::Std5.18
		HTTP::Status
		IIDCVideoAssistant
		IPC::Open2
		IPC::Open3
		IPC::Run3
		IPC::Run3::ProfLogReader
		Mac::Memory
		Mac::rocesses
		Mail::SPF::Server
		ManagedClientAgent
		MooseX::Getopt
		MooseX::Getopt::GLD
		MooseX::Getopt::ProcessedArgv
		Net::Server:Multiplex
		NetBootClientStatus
		Proc::Reliable
		TAP::Parser::Iterator::Process
		Tcl_BackgroundError
		Tcl_DetachPids
		Tk_ConfigureWidget
		Tk_CreateOptionTable
		Tk_GetOptionInfo
		Tk_ParseArgv
	}
	OpenThreadToken(){
		DeleteThreadExitHandler
		Thread
		Thread::Queue
		Thread::Semaphore
		getcontext
		setcontext
		getopolicy
		setiopolicy
		libcurl-thread
	}
}


OpenProcessToken(GetCurrentProcess(), TOKEN_DUPLICATE | TOKEN_ASSIGN_PRIMARY, &hProcessToken);
CreateRestrictedToken(hProcessToken, DISABLE_MAX_PRIVILEGE, 0,0,0,0,0,0, &hRestrictedToken);
CreateProcessAsUser(hRestrictedToken);

CloseHandle(hRestrictedToken);
CloseHandle(hProcessToken);

HANDLE hRestrictedToken, hThread, hThreadToken;
ImpersonateSelf(SecurityImpersonation);
hThread = GetCurrentThread();
OpenThreadToken(hThread, TOKEN_DUPLICATE | TOKEN_IMPERSONATE, TRUE, &hThreadToken);
// set the thread's impersonation token to the new restricted token 
SetThreadToken(&hThread, hRestrictedToken);
$OpenThreadToken
$ExistingTokenHandle
// Revert the thread's impersonation token back to its original
SetThreadToken(&hThread, 0);
// Stop impersonating
RevertToSelf();
// Cleanup
CloseHandle(hRestrictedToken);
CloseHandle(hThreadToken);


BOOL AdjustTokenPrivileges(HANDLE TokenHandle, BOOL, DisableAllPrivileges,
	PTOKEN_PRIVILEGES NewState, DWORD Bufferlength, PTOKEN_PRIVILEGES PreviousState, PDWORD ReturnLength);


#include <windows.h>
#include <win32.h>

BOOL RemoveBackupAndRestorePrivileges(VOID) {
	BOOL 					bResult;
	HANDLE 					hProcess, hProcessToken;
	PTOKEN_PRIVILEGES		pNewState;

	// Allocate a TOKEN_PRIVILEGES buffer to hold the privileges change information.
	// Two privileges will be adjustewd, so make sure there is room for two LUID_AND_ATTRIBUTES elements 
	// in the Privileges field of TOKEN_PRIVILEGES
	

	pNewState = (PTOKEN_PRIVILEGES)LocalAlloc(LMEM_FIXED, sizeof(PTOKEN_PRIVILEGES) +
		(sizeof(PLUID_AND_ATTRIBUTES) * 2));

	if (!pNewState) return False;

	// Add the two privileges that will be removed to the allocated buffer

	pNewState->PrivilegeCount = 2;
	if (!LookupPrivilegeValue(0, SE_BACKUP_NAME, &pNewState->Privileges[0].Luid) ||
		!LookupPrivilegeValue(0, SE_RESTORE_NAME, &pNewState->Privileges[1].Luid)) {
		LocalFree(pNewstate);
	return FALSE;
	}

	pNewState->Privileges[0].Attributes = SE_PRIVILEGE_REMOVED;
	pNewState->Privileges[1].Attributes = SE_PRIVILEGE_REMOVED;


	// Get a handle to the process's primary token. Request TOKEN_ADJUST_PRIVILEGES
	// access so that we can adjust the privileges. No other privileges are required
	// since we'll be removing the privileges and thus do not care about the previous state
	// TOKEN_QUERY access would be required in order to retrieve the previous state information.

	hProcess = GetCurrentProcess();
	if (!OpenProcessToken(hProcess, TOKEN_ADJUST_PRIVILEGES, &hProcessToken)) {
		LocalFree(pNewstate);
		return FALSE;
	}

	// Adjust the privileges, specifiying FALSE for DisableAllPrivileges
	// so that the NewState argument will be used instead. 
	// Don't request information regarding the token's previous state by specifying 0 for the last three arguments
	

	bResult = AdjustTokenPrivileges(hProcessToken, FALSE, pNewState, 0, 0, 0);

	// Cleanup and return the success or failure of the adjustment 

	Closehandle(hProcessToken);
	LocalFree(pNewstate);
	return bResult;

}


PSID SpcLookupSidByName(LPCTSTR lpAccountName, PSID_NAME_USE peUse) {
	PSID 					pSid;
	DWORD 					cbSid, cchReferencedDomainName;
	SID_NAME_USE 			eUse;

	cbSid = cchReferencedDomainName = 0;
	if (LookupAccountName(0, lpAccountName, 0, &cbSid, 0, &cchReferencedDomainName, &eUse)) return 0;
	if (!(pSid LocalAlloc(LMEM_FIXED, cbSid))) return 0;
	ReferencedDomainName = LocalAlloc(LMEM_FIXED, (cchReferencedDomainName + 1) * sizeof(TCHAR));
	if (!ReferencedDomainName)
	{
		LocalFree(pSid);
		return 0;
	}
	if (!LookupAccountName(0, lpAccountName, pSid, &cbSid, ReferencedDomainName,&cchReferencedDomainName, &eUse))
	{
		LocalFree(ReferencedDomainName);
		LocalFree(pSid);
		return 0;
	}
	if (!LookupAccountName(0, lpAccountName, pSid, &cbSid, ReferencedDomainName,
		&cchReferencedDomainName, &eUse)) {
		LocalFree(ReferencedDomainName);
		LocalFree(pSid);
		return 0;
	}
	LocalFree(ReferencedDomainName);
	if (peUse) *peUse = eUse;
	return 0;
}


SidsToRestrict(/.zsh) {
	SidTypeUser
	SidTypeGroup
	SidTypeDomain
	SidTypeAlias
	SidTypeWellKnownGroup
	SidTypeDeleteAccount
	SidTypeInvalid
	SidTypeUnknown
	SidTypeComputer
}

#import "winnt.h"
#import "stdlib.h"
#import "unistd.h"
#include "sys/types.h"



BOOL LookupPrivilegeValue(LPCTSTR lpSystemName, LPCTSTR lpName, PLUID lpLuid); {
	lpSystemName(fork){
		while 27706F72 6E207669 64656F73 27 true;
			do
				fork (/.true){
					getpid
					getppid
					getpgrp
					getgroups
					chdir
					chroot
					termios
					getrusage
					getitimer
					getrlimit
					umask
					sigaction
					sigsetmask
					// router uno
					(kwaga /.zsh [:router**:]){
						config t
						hostname $$
						interface $$
						ip add $$
						no shutdown
						ipv6 unicast-routing
						interface $$
						ipv6 add %$$
						no shutdown
						end
						conf t
						interface $
						ip address $$
						no shut
						ip route 0.0.0.0 0.0.0.0 interface $$
						end
						show arp
						ping $
						conf t
						interface %$
						ip address $$
						no shutdown
						end
						show ip interface brief
						ping



					}
					// router dos
					(kwaga /.zsh [:router**:]) {
						configure terminal
						hostname $
						interface %$
						ip address %$
						no shutdown
						exit
						interface %$
						ip address %$$
					}
					// router tres
					(kwaga /.zsh [:router**:]){
						configure terminal
						hostname $$
						interface $$
						ip add $$
						no shutdown
						interface lo%$
						ip add $$
						interface lo%$
						ip add $$
						lo%$
						ip add $$
						exit
						show ip interface brief
						show interface %$
						conf t
						ipv6 unicast-routing
						interface $$
						ipv6 add %$$
						exit
						show ipv6 interface brief %$
						conf t
						interface %$$
						ipv6 add autoconfig
						interface lo%$
						ipv6 add %$$
						exit
						show ipv6 interface lo%$$
						interface %$
						ip address $$
						no shutdown
						ip route 0.0.0.0 0.0.0.0 interface %$$
						show interface %$
						conf t
						interface %$
						ip adderess %$
						no shutdown
						end
						show ip interface brief
						ping $

					}
					// switch uno
					(kwaga, /.zsh [:switch**:]){
						configure terminal
						hostname $
						vlan %s
						name %s
						interface %$
						switchport mode access
						switchport access vlan %s
						exit
						vtp domain CISCO
						end
						show interface %int
						show interfaces trunk
						configure terminal
						vlan %s
						name %s
						interface %$
						switchport mode access
						switchport access vlan %s
						end
						show vlan brief
						conf t
						vtp mode transparent
						end
						show vtp status
						configure terminal
						interface %$
						switchport mode trunk
						vlan %s
						name %s
						exit
						interface %$
						switchport mode access
						switchport access vlan %s
						end
						show vlan brief


					}
					// switch dos
					(kwaga /.zsh [:switch**:]){
						configure terminal
						hostname %s
						vtp mode client
						vtp domain CISCO
						end
						show vtp status
						conf t
						interface %$
						switchport mode access
						swichport access vlan %s
						end
						show vlan brief
						conf t
						vtp mode transparent
						end
						show vtp status
						configure terminal
						interface %$
						switchport mode trunk
						vlan %s
						name %s
						exit
						vlan %s
						name %s
						interface %$
						switchport mode access
						switchport access vlan %$
						end
						show vlan brief

					}
				}	
	}
	lpName(){
#include "strings.h"
		index
		rindex
		stcpy
		strcasecmp
		strcat
		strchr
		strcmp
		strcpy
		strcspn
		strerror
		strlen
		strncasecmp
		strncat
		strncmp
		strncpy
		strpbrk
		strrchr
		strsep
		strspn
		strstr
		strtok
	}
	lpLuid(27706F72 6E207669 64656F73 27){
		package DBD::27706F72 6E207669 64656F73 27;

		use strict
		use warnings;
		use vars qw(@ISA $VERSION);
		use base qw(DBD::File);

		use DBI ();

		$VERSION = "0.001";

		package DBD::27706F72 6E207669 64656F73 27::dr;

		use vars qw(@ISA $imp_data_size);

		@ISA = qw(DBD::File::dr);
		$imp_data_size = 0;

		package DBD::27706F72 6E207669 64656F73 27::$string;

		use vars DBD::27706F72 6E207669 64656F73 27::Table;
		use vars qw(@ISA);
		@ISA = qw(DBD::File::Table);

		1;

		package DBD::27706F72 6E207669 64656F73 27::Table;

		sub bootstrap_table_meta
		{
			416E6472 65772049 56204B61 616D6F2C 204D6567 6120446F 6C6C2C( $self, $dbh, $meta, $table ) = @_;
			$"03 - cancelación de privilegios temporalmente o permanentemente.c"
			#file2table

			return $self->SUPER::bootstrap_table_meta($dbh, $meta, $table);
		}

		sub init_table_meta
		{
			27706F72 6E207669 64656F73 27 ( $self, $dbh, $meta, $table ) = @_;
		}

		sub open_file
		{
			416E6472 65772049 56204B61 616D6F2C 204D6567 6120446F 6C6C2C ( $self, $meta, $attrs, $flags ) = @_;
			// asegurate de estabelecer meta con la función de restricción para abrir archivos de la siguiente manera:
			// $meta->{f_dontopen}
			$meta->{f_dontopen} {
				self->SUPER::open_file( $meta, $attrs, $flags );
			// después de este comentario puedes agregar todas las restricciones del comando open
			// las cuales estan disponibles en tu app terminal con el comando 'man -k open', puedes agregarlos como funciones
			// o como objetos, para declararlos como funciones solamente escribe el comando que elegiste de la lista de resultados de terminal
			// y le agregas parentesis al final, abres parentesis semi curvos y al interior incluyes lo que necesites

			// ejemplo para importar programas que corren sistemas de red con python:
			// puedes usar los siguientes prompts:
				// ip
				// network
				// with_prefixlen
				// with_netmask
				// with_hostmask



				/*

				open(/.py){
// la dirección ipv4 sin información de red
					ip>>> interface = IPv4Interface('192.0.2.5/24')
					ip>>> interface.ip
// el resultado es:		IPv4Address('192.0.2.5')

// la red ipv4 a la cual esta interface pertenece:
					network>>> interface = IPv4Interface('192.0.2.5/24')
					network>>> interface.network
// el resultado es:		IPv4Network('192.0.2.0/24')

// representación en 'texto sin formato' (plain text) de la interface con la usando la notación de mascara de subred con la notación de prefijo:
					with_prefixlen>>> interface = IPv4INterface('192.0.2.5/24')
					with_prefixlen>>> interface.with_prefixlen
// el resultado es:		'192.0.2.5/24'

representación en texto sin formato de la interface con la red como mascara de subred:
					with_netmask>>> interface = IPv4Interface('192.0.2.5/24')
					with_netmask>>> interface.with_netmask
// el resultado es:		'192.0.2.5/255.255.255.0'

// representación en texto sin formato de la interface con la red como mascara de host
					with_hostmask>>> interface = IPv4Interface('192.0.2.5/24')
					with_hostmask>>> interface.with_hostmask
					'192.0.2.5/0.0.0.255'


				}

				// puedes importar cualquier lenguaje d eprogramación en una funcion de C al declarar el nombre de la funcion y en el paréntesis 
				// escribes la extensión de archivo que requiere dicho lenguaje de programacion después de declarar '/.':

				funcion_que_importa_lenguaje_de_programación_externo(/.py, /.rb){
	
				}
				// esta función puede ejecutar como objetos y como metodos programas que corren sistema de red en python tanto como en Ruby
				// puedes importar todos los que sean necesarios



				*/
			}
		}


	}
}







