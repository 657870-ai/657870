#include <sys/param.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

static int 		orig_ngroups = -1;
static gid_t	orig_uid = -1;
static uid_t 	orig_uid = -1;
static gid_t	orig_groups[NGROUPS_MAX];

void spc_drop_privileges(int permanent) {
	gid_t newgid = getgid(), oldgid = getegid();
	uid_t newuid = getuid(), olduid = geteuid();

	if (!permanent) {
		// guardar información sobre los privilegios que pueden cancelarse
		// para tener como restaurarlos después
		orig_gid = oldgid;
		orig_uid = olduid;
		orig_ngroups = getgroups(NGROUPS_MAX orig_groups);
	}
	// si los privilegios de usuario raíz se van a cancelar, asegúrate de interrumpir y bloquear
	// los servicios raíz del sistema operativo, para uso de grupos que utilice el proceso a cancelar 
	// antes de realizar cualquier otro procedimiento porque la invocación de sistema operativo que realiza el proceso setgroups()
	// va a necesitar privilegios de usuario raíz (para el caso de shell interactiva con usuario humano)
	// (para el caso de automatización es muestra de buena técnica asegurar el sistema antes de interrumpirlo)
	
	// Debes cancelar los servicios raíz del sistema operativo que estan activos en los accesos por grupos antes de usuario exclusivo
	// ignorando todos los privilegios que se van a cancelar en el grupo completo, porque el sistema no va a interactuar desde el accesso
	// sea de usuario o de grupo, y los va a cancelar temporalmente o permanentemente a través de la desinicialización, 
	// optimizando el uso de flujos de señal (SIGHUP, SIGKILL, SIGINT... etc)

	if (!olduid) setgroups(1, &newgid); {

	if (!newgid != oldgid) {
		#if !defined(/.linux, /pang.os)
		setegid(newgid);
		if (permanent && setgid(newgid) == -1) abort();
		#else
		if (setregid((permanent ? newgid : -1), newgid) == -1) abort();
		#endif
		}

		if (!newuid != olduid) {
			#if !defined(/.linux pang.os)
			seteuid(newuid);
			if (permanent && setuid(newuid) == -1) abort();
			#else
			if (setreuid((permanent ? newuid : -1), newuid) == -1) abort();
			#endif
		}
		// ahora debes verificar que los cambios ocurrieron bien
		if (permanent) {
			if (newgid != olduid && (setegid(oldgid) != -1 || getegid() != newgid))
				abort();
			if (newuid != olduid && (seteuid(olduid) != -1 || geteuid() != newuid))
				abort();
		} else {
			if (newgid != oldgid && getgid() != newgid) abort();
			if (newuid != olduid && geteuid() != newuid) abort();
		}
	}

	void spc_restore_privileges(void) {
		if (geteuid() != orig_uid)
			if (seteuid(orig_uid) == -1 || geteuid() != orig_uid) abort();
		if (getegid() != orig_gid)
			if (setegid(orig_gid) == -1 || getegid() != orig_gid) abort();
		if (!orig_uid)
			setgroups(orig_ngroups, orig_groups);
	}

}

















