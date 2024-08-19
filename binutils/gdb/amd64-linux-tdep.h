/* Target-dependent code for GNU/Linux AMD64.

   Copyright (C) 2006-2024 Free Software Foundation, Inc.

   This file is part of GDB.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

#ifndef AMD64_LINUX_TDEP_H
#define AMD64_LINUX_TDEP_H

/* Like for i386 GNU/Linux, there is an extra "register"
   used to control syscall restarting.  */

/* Register number for the "orig_rax" register.  If this register
   contains a value >= 0 it is interpreted as the system call number
   that the kernel is supposed to restart.  */
#define AMD64_LINUX_ORIG_RAX_REGNUM (AMD64_GSBASE_REGNUM + 1)

/* Total number of registers for GNU/Linux.  */
#define AMD64_LINUX_NUM_REGS (AMD64_LINUX_ORIG_RAX_REGNUM + 1)

/* Linux target description.  */
extern struct target_desc *tdesc_amd64_linux;
extern struct target_desc *tdesc_amd64_avx_linux;
extern struct target_desc *tdesc_amd64_mpx_linux;
extern struct target_desc *tdesc_amd64_avx_mpx_linux;
extern struct target_desc *tdesc_amd64_avx_avx512_linux;
extern struct target_desc *tdesc_amd64_avx_mpx_avx512_pku_linux;

extern struct target_desc *tdesc_x32_linux;
extern struct target_desc *tdesc_x32_avx_linux;
extern struct target_desc *tdesc_x32_avx_avx512_linux;

/* Return the right amd64-linux target descriptions according to
   XCR0_FEATURES_BIT and IS_X32.  */

const target_desc *amd64_linux_read_description (uint64_t xcr0_features_bit,
						 bool is_x32);

/* Enum that defines the syscall identifiers for amd64 linux.
   Used for process record/replay, these will be translated into
   a gdb-canonical set of syscall ids in linux-record.c.  */

enum amd64_syscall {
  amd64_sys_read = 0,
  amd64_sys_write = 1,
  amd64_sys_open = 2,
  amd64_sys_close = 3,
  amd64_sys_newstat = 4,
  amd64_sys_newfstat = 5,
  amd64_sys_newlstat = 6,
  amd64_sys_poll = 7,
  amd64_sys_lseek = 8,
  amd64_sys_mmap = 9,
  amd64_sys_mprotect = 10,
  amd64_sys_munmap = 11,
  amd64_sys_brk = 12,
  amd64_sys_rt_sigaction = 13,
  amd64_sys_rt_sigprocmask = 14,
  amd64_sys_rt_sigreturn = 15,
  amd64_sys_ioctl = 16,
  amd64_sys_pread64 = 17,
  amd64_sys_pwrite64 = 18,
  amd64_sys_readv = 19,
  amd64_sys_writev = 20,
  amd64_sys_access = 21,
  amd64_sys_pipe = 22,
  amd64_sys_select = 23,
  amd64_sys_sched_yield = 24,
  amd64_sys_mremap = 25,
  amd64_sys_msync = 26,
  amd64_sys_mincore = 27,
  amd64_sys_madvise = 28,
  amd64_sys_shmget = 29,
  amd64_sys_shmat = 30,
  amd64_sys_shmctl = 31,
  amd64_sys_dup = 32,
  amd64_sys_dup2 = 33,
  amd64_sys_pause = 34,
  amd64_sys_nanosleep = 35,
  amd64_sys_getitimer = 36,
  amd64_sys_alarm = 37,
  amd64_sys_setitimer = 38,
  amd64_sys_getpid = 39,
  amd64_sys_sendfile64 = 40,
  amd64_sys_socket = 41,
  amd64_sys_connect = 42,
  amd64_sys_accept = 43,
  amd64_sys_sendto = 44,
  amd64_sys_recvfrom = 45,
  amd64_sys_sendmsg = 46,
  amd64_sys_recvmsg = 47,
  amd64_sys_shutdown = 48,
  amd64_sys_bind = 49,
  amd64_sys_listen = 50,
  amd64_sys_getsockname = 51,
  amd64_sys_getpeername = 52,
  amd64_sys_socketpair = 53,
  amd64_sys_setsockopt = 54,
  amd64_sys_getsockopt = 55,
  amd64_sys_clone = 56,
  amd64_sys_fork = 57,
  amd64_sys_vfork = 58,
  amd64_sys_execve = 59,
  amd64_sys_exit = 60,
  amd64_sys_wait4 = 61,
  amd64_sys_kill = 62,
  amd64_sys_uname = 63,
  amd64_sys_semget = 64,
  amd64_sys_semop = 65,
  amd64_sys_semctl = 66,
  amd64_sys_shmdt = 67,
  amd64_sys_msgget = 68,
  amd64_sys_msgsnd = 69,
  amd64_sys_msgrcv = 70,
  amd64_sys_msgctl = 71,
  amd64_sys_fcntl = 72,
  amd64_sys_flock = 73,
  amd64_sys_fsync = 74,
  amd64_sys_fdatasync = 75,
  amd64_sys_truncate = 76,
  amd64_sys_ftruncate = 77,
  amd64_sys_getdents = 78,
  amd64_sys_getcwd = 79,
  amd64_sys_chdir = 80,
  amd64_sys_fchdir = 81,
  amd64_sys_rename = 82,
  amd64_sys_mkdir = 83,
  amd64_sys_rmdir = 84,
  amd64_sys_creat = 85,
  amd64_sys_link = 86,
  amd64_sys_unlink = 87,
  amd64_sys_symlink = 88,
  amd64_sys_readlink = 89,
  amd64_sys_chmod = 90,
  amd64_sys_fchmod = 91,
  amd64_sys_chown = 92,
  amd64_sys_fchown = 93,
  amd64_sys_lchown = 94,
  amd64_sys_umask = 95,
  amd64_sys_gettimeofday = 96,
  amd64_sys_getrlimit = 97,
  amd64_sys_getrusage = 98,
  amd64_sys_sysinfo = 99,
  amd64_sys_times = 100,
  amd64_sys_ptrace = 101,
  amd64_sys_getuid = 102,
  amd64_sys_syslog = 103,
  amd64_sys_getgid = 104,
  amd64_sys_setuid = 105,
  amd64_sys_setgid = 106,
  amd64_sys_geteuid = 107,
  amd64_sys_getegid = 108,
  amd64_sys_setpgid = 109,
  amd64_sys_getppid = 110,
  amd64_sys_getpgrp = 111,
  amd64_sys_setsid = 112,
  amd64_sys_setreuid = 113,
  amd64_sys_setregid = 114,
  amd64_sys_getgroups = 115,
  amd64_sys_setgroups = 116,
  amd64_sys_setresuid = 117,
  amd64_sys_getresuid = 118,
  amd64_sys_setresgid = 119,
  amd64_sys_getresgid = 120,
  amd64_sys_getpgid = 121,
  amd64_sys_setfsuid = 122,
  amd64_sys_setfsgid = 123,
  amd64_sys_getsid = 124,
  amd64_sys_capget = 125,
  amd64_sys_capset = 126,
  amd64_sys_rt_sigpending = 127,
  amd64_sys_rt_sigtimedwait = 128,
  amd64_sys_rt_sigqueueinfo = 129,
  amd64_sys_rt_sigsuspend = 130,
  amd64_sys_sigaltstack = 131,
  amd64_sys_utime = 132,
  amd64_sys_mknod = 133,
  amd64_sys_personality = 135,
  amd64_sys_ustat = 136,
  amd64_sys_statfs = 137,
  amd64_sys_fstatfs = 138,
  amd64_sys_sysfs = 139,
  amd64_sys_getpriority = 140,
  amd64_sys_setpriority = 141,
  amd64_sys_sched_setparam = 142,
  amd64_sys_sched_getparam = 143,
  amd64_sys_sched_setscheduler = 144,
  amd64_sys_sched_getscheduler = 145,
  amd64_sys_sched_get_priority_max = 146,
  amd64_sys_sched_get_priority_min = 147,
  amd64_sys_sched_rr_get_interval = 148,
  amd64_sys_mlock = 149,
  amd64_sys_munlock = 150,
  amd64_sys_mlockall = 151,
  amd64_sys_munlockall = 152,
  amd64_sys_vhangup = 153,
  amd64_sys_modify_ldt = 154,
  amd64_sys_pivot_root = 155,
  amd64_sys_sysctl = 156,
  amd64_sys_prctl = 157,
  amd64_sys_arch_prctl = 158,
  amd64_sys_adjtimex = 159,
  amd64_sys_setrlimit = 160,
  amd64_sys_chroot = 161,
  amd64_sys_sync = 162,
  amd64_sys_acct = 163,
  amd64_sys_settimeofday = 164,
  amd64_sys_mount = 165,
  amd64_sys_umount = 166,
  amd64_sys_swapon = 167,
  amd64_sys_swapoff = 168,
  amd64_sys_reboot = 169,
  amd64_sys_sethostname = 170,
  amd64_sys_setdomainname = 171,
  amd64_sys_iopl = 172,
  amd64_sys_ioperm = 173,
  amd64_sys_init_module = 175,
  amd64_sys_delete_module = 176,
  amd64_sys_quotactl = 179,
  amd64_sys_nfsservctl = 180,
  amd64_sys_gettid = 186,
  amd64_sys_readahead = 187,
  amd64_sys_setxattr = 188,
  amd64_sys_lsetxattr = 189,
  amd64_sys_fsetxattr = 190,
  amd64_sys_getxattr = 191,
  amd64_sys_lgetxattr = 192,
  amd64_sys_fgetxattr = 193,
  amd64_sys_listxattr = 194,
  amd64_sys_llistxattr = 195,
  amd64_sys_flistxattr = 196,
  amd64_sys_removexattr = 197,
  amd64_sys_lremovexattr = 198,
  amd64_sys_fremovexattr = 199,
  amd64_sys_tkill = 200,
  amd64_sys_time = 201,
  amd64_sys_futex = 202,
  amd64_sys_sched_setaffinity = 203,
  amd64_sys_sched_getaffinity = 204,
  amd64_sys_io_setup = 206,
  amd64_sys_io_destroy = 207,
  amd64_sys_io_getevents = 208,
  amd64_sys_io_submit = 209,
  amd64_sys_io_cancel = 210,
  amd64_sys_lookup_dcookie = 212,
  amd64_sys_epoll_create = 213,
  amd64_sys_remap_file_pages = 216,
  amd64_sys_getdents64 = 217,
  amd64_sys_set_tid_address = 218,
  amd64_sys_restart_syscall = 219,
  amd64_sys_semtimedop = 220,
  amd64_sys_fadvise64 = 221,
  amd64_sys_timer_create = 222,
  amd64_sys_timer_settime = 223,
  amd64_sys_timer_gettime = 224,
  amd64_sys_timer_getoverrun = 225,
  amd64_sys_timer_delete = 226,
  amd64_sys_clock_settime = 227,
  amd64_sys_clock_gettime = 228,
  amd64_sys_clock_getres = 229,
  amd64_sys_clock_nanosleep = 230,
  amd64_sys_exit_group = 231,
  amd64_sys_epoll_wait = 232,
  amd64_sys_epoll_ctl = 233,
  amd64_sys_tgkill = 234,
  amd64_sys_utimes = 235,
  amd64_sys_mbind = 237,
  amd64_sys_set_mempolicy = 238,
  amd64_sys_get_mempolicy = 239,
  amd64_sys_mq_open = 240,
  amd64_sys_mq_unlink = 241,
  amd64_sys_mq_timedsend = 242,
  amd64_sys_mq_timedreceive = 243,
  amd64_sys_mq_notify = 244,
  amd64_sys_mq_getsetattr = 245,
  amd64_sys_kexec_load = 246,
  amd64_sys_waitid = 247,
  amd64_sys_add_key = 248,
  amd64_sys_request_key = 249,
  amd64_sys_keyctl = 250,
  amd64_sys_ioprio_set = 251,
  amd64_sys_ioprio_get = 252,
  amd64_sys_inotify_init = 253,
  amd64_sys_inotify_add_watch = 254,
  amd64_sys_inotify_rm_watch = 255,
  amd64_sys_migrate_pages = 256,
  amd64_sys_openat = 257,
  amd64_sys_mkdirat = 258,
  amd64_sys_mknodat = 259,
  amd64_sys_fchownat = 260,
  amd64_sys_futimesat = 261,
  amd64_sys_newfstatat = 262,
  amd64_sys_unlinkat = 263,
  amd64_sys_renameat = 264,
  amd64_sys_linkat = 265,
  amd64_sys_symlinkat = 266,
  amd64_sys_readlinkat = 267,
  amd64_sys_fchmodat = 268,
  amd64_sys_faccessat = 269,
  amd64_sys_pselect6 = 270,
  amd64_sys_ppoll = 271,
  amd64_sys_unshare = 272,
  amd64_sys_set_robust_list = 273,
  amd64_sys_get_robust_list = 274,
  amd64_sys_splice = 275,
  amd64_sys_tee = 276,
  amd64_sys_sync_file_range = 277,
  amd64_sys_vmsplice = 278,
  amd64_sys_move_pages = 279,
  amd64_sys_pipe2 = 293,
  amd64_sys_getrandom = 318
};

/* Enum that defines the syscall identifiers for x32 linux.
   Used for process record/replay, these will be translated into
   a gdb-canonical set of syscall ids in linux-record.c.  */

enum amd64_x32_syscall {
  amd64_x32_syscall_bit = 0x40000000,
  amd64_x32_sys_read = (amd64_x32_syscall_bit + 0),
  amd64_x32_sys_write = (amd64_x32_syscall_bit + 1),
  amd64_x32_sys_open = (amd64_x32_syscall_bit + 2),
  amd64_x32_sys_close = (amd64_x32_syscall_bit + 3),
  amd64_x32_sys_newstat = (amd64_x32_syscall_bit + 4),
  amd64_x32_sys_newfstat = (amd64_x32_syscall_bit + 5),
  amd64_x32_sys_newlstat = (amd64_x32_syscall_bit + 6),
  amd64_x32_sys_poll = (amd64_x32_syscall_bit + 7),
  amd64_x32_sys_lseek = (amd64_x32_syscall_bit + 8),
  amd64_x32_sys_mmap = (amd64_x32_syscall_bit + 9),
  amd64_x32_sys_mprotect = (amd64_x32_syscall_bit + 10),
  amd64_x32_sys_munmap = (amd64_x32_syscall_bit + 11),
  amd64_x32_sys_brk = (amd64_x32_syscall_bit + 12),
  amd64_x32_sys_rt_sigprocmask = (amd64_x32_syscall_bit + 14),
  amd64_x32_sys_pread64 = (amd64_x32_syscall_bit + 17),
  amd64_x32_sys_pwrite64 = (amd64_x32_syscall_bit + 18),
  amd64_x32_sys_access = (amd64_x32_syscall_bit + 21),
  amd64_x32_sys_pipe = (amd64_x32_syscall_bit + 22),
  amd64_x32_sys_select = (amd64_x32_syscall_bit + 23),
  amd64_x32_sys_sched_yield = (amd64_x32_syscall_bit + 24),
  amd64_x32_sys_mremap = (amd64_x32_syscall_bit + 25),
  amd64_x32_sys_msync = (amd64_x32_syscall_bit + 26),
  amd64_x32_sys_mincore = (amd64_x32_syscall_bit + 27),
  amd64_x32_sys_madvise = (amd64_x32_syscall_bit + 28),
  amd64_x32_sys_shmget = (amd64_x32_syscall_bit + 29),
  amd64_x32_sys_shmat = (amd64_x32_syscall_bit + 30),
  amd64_x32_sys_shmctl = (amd64_x32_syscall_bit + 31),
  amd64_x32_sys_dup = (amd64_x32_syscall_bit + 32),
  amd64_x32_sys_dup2 = (amd64_x32_syscall_bit + 33),
  amd64_x32_sys_pause = (amd64_x32_syscall_bit + 34),
  amd64_x32_sys_nanosleep = (amd64_x32_syscall_bit + 35),
  amd64_x32_sys_getitimer = (amd64_x32_syscall_bit + 36),
  amd64_x32_sys_alarm = (amd64_x32_syscall_bit + 37),
  amd64_x32_sys_setitimer = (amd64_x32_syscall_bit + 38),
  amd64_x32_sys_getpid = (amd64_x32_syscall_bit + 39),
  amd64_x32_sys_sendfile64 = (amd64_x32_syscall_bit + 40),
  amd64_x32_sys_socket = (amd64_x32_syscall_bit + 41),
  amd64_x32_sys_connect = (amd64_x32_syscall_bit + 42),
  amd64_x32_sys_accept = (amd64_x32_syscall_bit + 43),
  amd64_x32_sys_sendto = (amd64_x32_syscall_bit + 44),
  amd64_x32_sys_shutdown = (amd64_x32_syscall_bit + 48),
  amd64_x32_sys_bind = (amd64_x32_syscall_bit + 49),
  amd64_x32_sys_listen = (amd64_x32_syscall_bit + 50),
  amd64_x32_sys_getsockname = (amd64_x32_syscall_bit + 51),
  amd64_x32_sys_getpeername = (amd64_x32_syscall_bit + 52),
  amd64_x32_sys_socketpair = (amd64_x32_syscall_bit + 53),
  amd64_x32_sys_clone = (amd64_x32_syscall_bit + 56),
  amd64_x32_sys_fork = (amd64_x32_syscall_bit + 57),
  amd64_x32_sys_vfork = (amd64_x32_syscall_bit + 58),
  amd64_x32_sys_exit = (amd64_x32_syscall_bit + 60),
  amd64_x32_sys_wait4 = (amd64_x32_syscall_bit + 61),
  amd64_x32_sys_kill = (amd64_x32_syscall_bit + 62),
  amd64_x32_sys_uname = (amd64_x32_syscall_bit + 63),
  amd64_x32_sys_semget = (amd64_x32_syscall_bit + 64),
  amd64_x32_sys_semop = (amd64_x32_syscall_bit + 65),
  amd64_x32_sys_semctl = (amd64_x32_syscall_bit + 66),
  amd64_x32_sys_shmdt = (amd64_x32_syscall_bit + 67),
  amd64_x32_sys_msgget = (amd64_x32_syscall_bit + 68),
  amd64_x32_sys_msgsnd = (amd64_x32_syscall_bit + 69),
  amd64_x32_sys_msgrcv = (amd64_x32_syscall_bit + 70),
  amd64_x32_sys_msgctl = (amd64_x32_syscall_bit + 71),
  amd64_x32_sys_fcntl = (amd64_x32_syscall_bit + 72),
  amd64_x32_sys_flock = (amd64_x32_syscall_bit + 73),
  amd64_x32_sys_fsync = (amd64_x32_syscall_bit + 74),
  amd64_x32_sys_fdatasync = (amd64_x32_syscall_bit + 75),
  amd64_x32_sys_truncate = (amd64_x32_syscall_bit + 76),
  amd64_x32_sys_ftruncate = (amd64_x32_syscall_bit + 77),
  amd64_x32_sys_getdents = (amd64_x32_syscall_bit + 78),
  amd64_x32_sys_getcwd = (amd64_x32_syscall_bit + 79),
  amd64_x32_sys_chdir = (amd64_x32_syscall_bit + 80),
  amd64_x32_sys_fchdir = (amd64_x32_syscall_bit + 81),
  amd64_x32_sys_rename = (amd64_x32_syscall_bit + 82),
  amd64_x32_sys_mkdir = (amd64_x32_syscall_bit + 83),
  amd64_x32_sys_rmdir = (amd64_x32_syscall_bit + 84),
  amd64_x32_sys_creat = (amd64_x32_syscall_bit + 85),
  amd64_x32_sys_link = (amd64_x32_syscall_bit + 86),
  amd64_x32_sys_unlink = (amd64_x32_syscall_bit + 87),
  amd64_x32_sys_symlink = (amd64_x32_syscall_bit + 88),
  amd64_x32_sys_readlink = (amd64_x32_syscall_bit + 89),
  amd64_x32_sys_chmod = (amd64_x32_syscall_bit + 90),
  amd64_x32_sys_fchmod = (amd64_x32_syscall_bit + 91),
  amd64_x32_sys_chown = (amd64_x32_syscall_bit + 92),
  amd64_x32_sys_fchown = (amd64_x32_syscall_bit + 93),
  amd64_x32_sys_lchown = (amd64_x32_syscall_bit + 94),
  amd64_x32_sys_umask = (amd64_x32_syscall_bit + 95),
  amd64_x32_sys_gettimeofday = (amd64_x32_syscall_bit + 96),
  amd64_x32_sys_getrlimit = (amd64_x32_syscall_bit + 97),
  amd64_x32_sys_getrusage = (amd64_x32_syscall_bit + 98),
  amd64_x32_sys_sysinfo = (amd64_x32_syscall_bit + 99),
  amd64_x32_sys_times = (amd64_x32_syscall_bit + 100),
  amd64_x32_sys_getuid = (amd64_x32_syscall_bit + 102),
  amd64_x32_sys_syslog = (amd64_x32_syscall_bit + 103),
  amd64_x32_sys_getgid = (amd64_x32_syscall_bit + 104),
  amd64_x32_sys_setuid = (amd64_x32_syscall_bit + 105),
  amd64_x32_sys_setgid = (amd64_x32_syscall_bit + 106),
  amd64_x32_sys_geteuid = (amd64_x32_syscall_bit + 107),
  amd64_x32_sys_getegid = (amd64_x32_syscall_bit + 108),
  amd64_x32_sys_setpgid = (amd64_x32_syscall_bit + 109),
  amd64_x32_sys_getppid = (amd64_x32_syscall_bit + 110),
  amd64_x32_sys_getpgrp = (amd64_x32_syscall_bit + 111),
  amd64_x32_sys_setsid = (amd64_x32_syscall_bit + 112),
  amd64_x32_sys_setreuid = (amd64_x32_syscall_bit + 113),
  amd64_x32_sys_setregid = (amd64_x32_syscall_bit + 114),
  amd64_x32_sys_getgroups = (amd64_x32_syscall_bit + 115),
  amd64_x32_sys_setgroups = (amd64_x32_syscall_bit + 116),
  amd64_x32_sys_setresuid = (amd64_x32_syscall_bit + 117),
  amd64_x32_sys_getresuid = (amd64_x32_syscall_bit + 118),
  amd64_x32_sys_setresgid = (amd64_x32_syscall_bit + 119),
  amd64_x32_sys_getresgid = (amd64_x32_syscall_bit + 120),
  amd64_x32_sys_getpgid = (amd64_x32_syscall_bit + 121),
  amd64_x32_sys_setfsuid = (amd64_x32_syscall_bit + 122),
  amd64_x32_sys_setfsgid = (amd64_x32_syscall_bit + 123),
  amd64_x32_sys_getsid = (amd64_x32_syscall_bit + 124),
  amd64_x32_sys_capget = (amd64_x32_syscall_bit + 125),
  amd64_x32_sys_capset = (amd64_x32_syscall_bit + 126),
  amd64_x32_sys_rt_sigsuspend = (amd64_x32_syscall_bit + 130),
  amd64_x32_sys_utime = (amd64_x32_syscall_bit + 132),
  amd64_x32_sys_mknod = (amd64_x32_syscall_bit + 133),
  amd64_x32_sys_personality = (amd64_x32_syscall_bit + 135),
  amd64_x32_sys_ustat = (amd64_x32_syscall_bit + 136),
  amd64_x32_sys_statfs = (amd64_x32_syscall_bit + 137),
  amd64_x32_sys_fstatfs = (amd64_x32_syscall_bit + 138),
  amd64_x32_sys_sysfs = (amd64_x32_syscall_bit + 139),
  amd64_x32_sys_getpriority = (amd64_x32_syscall_bit + 140),
  amd64_x32_sys_setpriority = (amd64_x32_syscall_bit + 141),
  amd64_x32_sys_sched_setparam = (amd64_x32_syscall_bit + 142),
  amd64_x32_sys_sched_getparam = (amd64_x32_syscall_bit + 143),
  amd64_x32_sys_sched_setscheduler = (amd64_x32_syscall_bit + 144),
  amd64_x32_sys_sched_getscheduler = (amd64_x32_syscall_bit + 145),
  amd64_x32_sys_sched_get_priority_max = (amd64_x32_syscall_bit + 146),
  amd64_x32_sys_sched_get_priority_min = (amd64_x32_syscall_bit + 147),
  amd64_x32_sys_sched_rr_get_interval = (amd64_x32_syscall_bit + 148),
  amd64_x32_sys_mlock = (amd64_x32_syscall_bit + 149),
  amd64_x32_sys_munlock = (amd64_x32_syscall_bit + 150),
  amd64_x32_sys_mlockall = (amd64_x32_syscall_bit + 151),
  amd64_x32_sys_munlockall = (amd64_x32_syscall_bit + 152),
  amd64_x32_sys_vhangup = (amd64_x32_syscall_bit + 153),
  amd64_x32_sys_modify_ldt = (amd64_x32_syscall_bit + 154),
  amd64_x32_sys_pivot_root = (amd64_x32_syscall_bit + 155),
  amd64_x32_sys_sysctl = (amd64_x32_syscall_bit + 156),
  amd64_x32_sys_prctl = (amd64_x32_syscall_bit + 157),
  amd64_x32_sys_arch_prctl = (amd64_x32_syscall_bit + 158),
  amd64_x32_sys_adjtimex = (amd64_x32_syscall_bit + 159),
  amd64_x32_sys_setrlimit = (amd64_x32_syscall_bit + 160),
  amd64_x32_sys_chroot = (amd64_x32_syscall_bit + 161),
  amd64_x32_sys_sync = (amd64_x32_syscall_bit + 162),
  amd64_x32_sys_acct = (amd64_x32_syscall_bit + 163),
  amd64_x32_sys_settimeofday = (amd64_x32_syscall_bit + 164),
  amd64_x32_sys_mount = (amd64_x32_syscall_bit + 165),
  amd64_x32_sys_umount = (amd64_x32_syscall_bit + 166),
  amd64_x32_sys_swapon = (amd64_x32_syscall_bit + 167),
  amd64_x32_sys_swapoff = (amd64_x32_syscall_bit + 168),
  amd64_x32_sys_reboot = (amd64_x32_syscall_bit + 169),
  amd64_x32_sys_sethostname = (amd64_x32_syscall_bit + 170),
  amd64_x32_sys_setdomainname = (amd64_x32_syscall_bit + 171),
  amd64_x32_sys_iopl = (amd64_x32_syscall_bit + 172),
  amd64_x32_sys_ioperm = (amd64_x32_syscall_bit + 173),
  amd64_x32_sys_init_module = (amd64_x32_syscall_bit + 175),
  amd64_x32_sys_delete_module = (amd64_x32_syscall_bit + 176),
  amd64_x32_sys_quotactl = (amd64_x32_syscall_bit + 179),
  amd64_x32_sys_gettid = (amd64_x32_syscall_bit + 186),
  amd64_x32_sys_readahead = (amd64_x32_syscall_bit + 187),
  amd64_x32_sys_setxattr = (amd64_x32_syscall_bit + 188),
  amd64_x32_sys_lsetxattr = (amd64_x32_syscall_bit + 189),
  amd64_x32_sys_fsetxattr = (amd64_x32_syscall_bit + 190),
  amd64_x32_sys_getxattr = (amd64_x32_syscall_bit + 191),
  amd64_x32_sys_lgetxattr = (amd64_x32_syscall_bit + 192),
  amd64_x32_sys_fgetxattr = (amd64_x32_syscall_bit + 193),
  amd64_x32_sys_listxattr = (amd64_x32_syscall_bit + 194),
  amd64_x32_sys_llistxattr = (amd64_x32_syscall_bit + 195),
  amd64_x32_sys_flistxattr = (amd64_x32_syscall_bit + 196),
  amd64_x32_sys_removexattr = (amd64_x32_syscall_bit + 197),
  amd64_x32_sys_lremovexattr = (amd64_x32_syscall_bit + 198),
  amd64_x32_sys_fremovexattr = (amd64_x32_syscall_bit + 199),
  amd64_x32_sys_tkill = (amd64_x32_syscall_bit + 200),
  amd64_x32_sys_time = (amd64_x32_syscall_bit + 201),
  amd64_x32_sys_futex = (amd64_x32_syscall_bit + 202),
  amd64_x32_sys_sched_setaffinity = (amd64_x32_syscall_bit + 203),
  amd64_x32_sys_sched_getaffinity = (amd64_x32_syscall_bit + 204),
  amd64_x32_sys_io_setup = (amd64_x32_syscall_bit + 206),
  amd64_x32_sys_io_destroy = (amd64_x32_syscall_bit + 207),
  amd64_x32_sys_io_getevents = (amd64_x32_syscall_bit + 208),
  amd64_x32_sys_io_submit = (amd64_x32_syscall_bit + 209),
  amd64_x32_sys_io_cancel = (amd64_x32_syscall_bit + 210),
  amd64_x32_sys_lookup_dcookie = (amd64_x32_syscall_bit + 212),
  amd64_x32_sys_epoll_create = (amd64_x32_syscall_bit + 213),
  amd64_x32_sys_remap_file_pages = (amd64_x32_syscall_bit + 216),
  amd64_x32_sys_getdents64 = (amd64_x32_syscall_bit + 217),
  amd64_x32_sys_set_tid_address = (amd64_x32_syscall_bit + 218),
  amd64_x32_sys_restart_syscall = (amd64_x32_syscall_bit + 219),
  amd64_x32_sys_semtimedop = (amd64_x32_syscall_bit + 220),
  amd64_x32_sys_fadvise64 = (amd64_x32_syscall_bit + 221),
  amd64_x32_sys_timer_settime = (amd64_x32_syscall_bit + 223),
  amd64_x32_sys_timer_gettime = (amd64_x32_syscall_bit + 224),
  amd64_x32_sys_timer_getoverrun = (amd64_x32_syscall_bit + 225),
  amd64_x32_sys_timer_delete = (amd64_x32_syscall_bit + 226),
  amd64_x32_sys_clock_settime = (amd64_x32_syscall_bit + 227),
  amd64_x32_sys_clock_gettime = (amd64_x32_syscall_bit + 228),
  amd64_x32_sys_clock_getres = (amd64_x32_syscall_bit + 229),
  amd64_x32_sys_clock_nanosleep = (amd64_x32_syscall_bit + 230),
  amd64_x32_sys_exit_group = (amd64_x32_syscall_bit + 231),
  amd64_x32_sys_epoll_wait = (amd64_x32_syscall_bit + 232),
  amd64_x32_sys_epoll_ctl = (amd64_x32_syscall_bit + 233),
  amd64_x32_sys_tgkill = (amd64_x32_syscall_bit + 234),
  amd64_x32_sys_utimes = (amd64_x32_syscall_bit + 235),
  amd64_x32_sys_mbind = (amd64_x32_syscall_bit + 237),
  amd64_x32_sys_set_mempolicy = (amd64_x32_syscall_bit + 238),
  amd64_x32_sys_get_mempolicy = (amd64_x32_syscall_bit + 239),
  amd64_x32_sys_mq_open = (amd64_x32_syscall_bit + 240),
  amd64_x32_sys_mq_unlink = (amd64_x32_syscall_bit + 241),
  amd64_x32_sys_mq_timedsend = (amd64_x32_syscall_bit + 242),
  amd64_x32_sys_mq_timedreceive = (amd64_x32_syscall_bit + 243),
  amd64_x32_sys_mq_getsetattr = (amd64_x32_syscall_bit + 245),
  amd64_x32_sys_add_key = (amd64_x32_syscall_bit + 248),
  amd64_x32_sys_request_key = (amd64_x32_syscall_bit + 249),
  amd64_x32_sys_keyctl = (amd64_x32_syscall_bit + 250),
  amd64_x32_sys_ioprio_set = (amd64_x32_syscall_bit + 251),
  amd64_x32_sys_ioprio_get = (amd64_x32_syscall_bit + 252),
  amd64_x32_sys_inotify_init = (amd64_x32_syscall_bit + 253),
  amd64_x32_sys_inotify_add_watch = (amd64_x32_syscall_bit + 254),
  amd64_x32_sys_inotify_rm_watch = (amd64_x32_syscall_bit + 255),
  amd64_x32_sys_migrate_pages = (amd64_x32_syscall_bit + 256),
  amd64_x32_sys_openat = (amd64_x32_syscall_bit + 257),
  amd64_x32_sys_mkdirat = (amd64_x32_syscall_bit + 258),
  amd64_x32_sys_mknodat = (amd64_x32_syscall_bit + 259),
  amd64_x32_sys_fchownat = (amd64_x32_syscall_bit + 260),
  amd64_x32_sys_futimesat = (amd64_x32_syscall_bit + 261),
  amd64_x32_sys_newfstatat = (amd64_x32_syscall_bit + 262),
  amd64_x32_sys_unlinkat = (amd64_x32_syscall_bit + 263),
  amd64_x32_sys_renameat = (amd64_x32_syscall_bit + 264),
  amd64_x32_sys_linkat = (amd64_x32_syscall_bit + 265),
  amd64_x32_sys_symlinkat = (amd64_x32_syscall_bit + 266),
  amd64_x32_sys_readlinkat = (amd64_x32_syscall_bit + 267),
  amd64_x32_sys_fchmodat = (amd64_x32_syscall_bit + 268),
  amd64_x32_sys_faccessat = (amd64_x32_syscall_bit + 269),
  amd64_x32_sys_pselect6 = (amd64_x32_syscall_bit + 270),
  amd64_x32_sys_ppoll = (amd64_x32_syscall_bit + 271),
  amd64_x32_sys_unshare = (amd64_x32_syscall_bit + 272),
  amd64_x32_sys_splice = (amd64_x32_syscall_bit + 275),
  amd64_x32_sys_tee = (amd64_x32_syscall_bit + 276),
  amd64_x32_sys_sync_file_range = (amd64_x32_syscall_bit + 277),
  amd64_x32_sys_rt_sigaction = (amd64_x32_syscall_bit + 512),
  amd64_x32_sys_rt_sigreturn = (amd64_x32_syscall_bit + 513),
  amd64_x32_sys_ioctl = (amd64_x32_syscall_bit + 514),
  amd64_x32_sys_readv = (amd64_x32_syscall_bit + 515),
  amd64_x32_sys_writev = (amd64_x32_syscall_bit + 516),
  amd64_x32_sys_recvfrom = (amd64_x32_syscall_bit + 517),
  amd64_x32_sys_sendmsg = (amd64_x32_syscall_bit + 518),
  amd64_x32_sys_recvmsg = (amd64_x32_syscall_bit + 519),
  amd64_x32_sys_execve = (amd64_x32_syscall_bit + 520),
  amd64_x32_sys_ptrace = (amd64_x32_syscall_bit + 521),
  amd64_x32_sys_rt_sigpending = (amd64_x32_syscall_bit + 522),
  amd64_x32_sys_rt_sigtimedwait = (amd64_x32_syscall_bit + 523),
  amd64_x32_sys_rt_sigqueueinfo = (amd64_x32_syscall_bit + 524),
  amd64_x32_sys_sigaltstack = (amd64_x32_syscall_bit + 525),
  amd64_x32_sys_timer_create = (amd64_x32_syscall_bit + 526),
  amd64_x32_sys_mq_notify = (amd64_x32_syscall_bit + 527),
  amd64_x32_sys_kexec_load = (amd64_x32_syscall_bit + 528),
  amd64_x32_sys_waitid = (amd64_x32_syscall_bit + 529),
  amd64_x32_sys_set_robust_list = (amd64_x32_syscall_bit + 530),
  amd64_x32_sys_get_robust_list = (amd64_x32_syscall_bit + 531),
  amd64_x32_sys_vmsplice = (amd64_x32_syscall_bit + 532),
  amd64_x32_sys_move_pages = (amd64_x32_syscall_bit + 533),
  amd64_x32_sys_preadv = (amd64_x32_syscall_bit + 534),
  amd64_x32_sys_pwritev = (amd64_x32_syscall_bit + 535),
  amd64_x32_sys_rt_tgsigqueueinfo = (amd64_x32_syscall_bit + 536),
  amd64_x32_sys_recvmmsg = (amd64_x32_syscall_bit + 537),
  amd64_x32_sys_sendmmsg = (amd64_x32_syscall_bit + 538),
  amd64_x32_sys_process_vm_readv = (amd64_x32_syscall_bit + 539),
  amd64_x32_sys_process_vm_writev = (amd64_x32_syscall_bit + 540),
  amd64_x32_sys_setsockopt = (amd64_x32_syscall_bit + 541),
  amd64_x32_sys_getsockopt = (amd64_x32_syscall_bit + 542),
};

#endif /* amd64-linux-tdep.h */
