##############################################################################
#
#
# Makefile for PRU run-time support library version 2.3.3
#
#
##############################################################################
#
# This Makefile is automatically-generated: you usually should not edit it. 
#
##############################################################################


##############################################################################
#
# This Makefile is specific to compiler RTS library version 2.3.3.  
# The format is subject to change without notice.  This Makefile is intended
# for use with mklib, which understands which 'make' variables to set to build
# each distinct version of the RTS library.
#
# This Makefile uses GNU make language extensions.
#
##############################################################################

##############################################################################
#
# GROUPS
#
# The source files are set up in a modular fashion using "groups."  Groups
# represent major feature clusters, and usually specify source files which
# implement that feature.  When building a library which needs a particular
# feature, the group which represents that feature is "activated" by setting a
# 'make' variable.  This variable can be set directly by the user, or may be
# inferred from the setting of other variables.  Groups (and the files they
# contain) not needed for a certain library are not activated.  Some groups
# are always activated.  Groups which are not always activated are enclosed in
# an "ifeq" testing the corresponding 'make' variable (the name of the
# variable is the name of the group).
#
# Groups can specify any kind of source file (e.g. C, C++, assembly), but do
# not list header files, or source files included from other source files.
# This Makefile is focused on how to build the object files, not listing all
# of the necessary files.  Some groups do not list any source files; these
# groups may still carry information such as extra options to use when that
# group is active, or may activate other groups.  Some groups exist only to be
# tested as part of the activation condition of other groups.
#
# Groups can specify extra compiler options to use when that group is active.
# These can be options intended for all targets (UNIVERSAL_FLAGS), such as the
# CPU version, or can be intended only for a certain type of files (CPP_FLAGS)
# (e.g. the option "--exceptions")
#
##############################################################################

##############################################################################
#
# OPTIONS
#
# You can append or override some options through 'make' variables specified
# on the command line.  Not all options can be changed this way, and some
# options are dangerous to use in a Makefile (e.g. "--skip_assembler").
# Options added by groups below should not be altered; if the option is
# undesired, you're probably building the wrong library.  For example, if you
# don't want "--exceptions", you shouldn't be using EXCEPTIONS=1.
#
# You can append options to the standard list by using EXTRA_FLAGS.  This is
# useful for enabling debugging support or activating silicon errata
# workarounds:
#
# gmake LIB=some.lib EXTRA_FLAGS="-g"
#
##############################################################################

##############################################################################
# Available libraries
#
# You can build each 2.3.3 library using the appropriate command:
#
# gmake library LIB=rtspruv1_be.lib BIG_ENDIAN=1 V1=1
# gmake library LIB=rtspruv1_be_eh.lib EXCEPTIONS=1 BIG_ENDIAN=1 FULL_PORTABLE_EH=1 V1=1
# gmake library LIB=rtspruv1_le.lib LITTLE_ENDIAN=1 V1=1
# gmake library LIB=rtspruv1_le_eh.lib V1=1 FULL_PORTABLE_EH=1 LITTLE_ENDIAN=1 EXCEPTIONS=1
# gmake library LIB=rtspruv2_be.lib BIG_ENDIAN=1 V2=1
# gmake library LIB=rtspruv2_be_eh.lib BIG_ENDIAN=1 EXCEPTIONS=1 V2=1 FULL_PORTABLE_EH=1
# gmake library LIB=rtspruv2_le.lib LITTLE_ENDIAN=1 V2=1
# gmake library LIB=rtspruv2_le_eh.lib EXCEPTIONS=1 V2=1 LITTLE_ENDIAN=1 FULL_PORTABLE_EH=1
# gmake library LIB=rtspruv3_be.lib V3=1 BIG_ENDIAN=1
# gmake library LIB=rtspruv3_be_eh.lib V3=1 BIG_ENDIAN=1 EXCEPTIONS=1 FULL_PORTABLE_EH=1
# gmake library LIB=rtspruv3_le.lib LITTLE_ENDIAN=1 V3=1
# gmake library LIB=rtspruv3_le_eh.lib EXCEPTIONS=1 V3=1 LITTLE_ENDIAN=1 FULL_PORTABLE_EH=1
##############################################################################

ifdef CMD_FILE
 -include $(CMD_FILE)
endif
#-----------------------------------------------------------------------------
# Basic definitions
#-----------------------------------------------------------------------------
ifeq (y,$(shell [ -e $(CGT_BIN)/clpru ] && echo y))
  CC = $(CGT_BIN)/clpru
else
  CC = clpru
endif
ifeq (y,$(shell [ -e $(CGT_BIN)/arpru ] && echo y))
  AR = $(CGT_BIN)/arpru
else
  AR = arpru
endif
CD = cd

#-----------------------------------------------------------------------------
# Group TARGET
#-----------------------------------------------------------------------------
UNIVERSAL_FLAGS += --mem_model:data=far

TARGET_C_SOURCE = \
	boot.c \
	mpyll.c \
	mpyi.c \
	asri.c \
	divi_c.c \
	divu_c.c \
	remi_c.c \
	remu_c.c \
	asrll.c \
	lslll.c \
	lsrll.c \
	divlli.c \
	divull.c \
	remlli.c \
	remull.c \
	autoinit.c \
	startup.c \
	cpy_tbl.c \
	copy_zero_init.c \
	copy_decompress_none.c \
	copy_decompress_rle.c \
	copy_decompress_lzss.c

C_SOURCE += $(TARGET_C_SOURCE)


TARGET_ASM_SOURCE = \
	memcpy.asm \
	setjmp.asm

ASM_SOURCE += $(TARGET_ASM_SOURCE)


#-----------------------------------------------------------------------------
# Group GENERIC_MATH_LIBRARY_DOUBLE_IS_64
#-----------------------------------------------------------------------------

#-----------------------------------------------------------------------------
# Group GENERIC_MATH_LIBRARY_FLOAT
#-----------------------------------------------------------------------------

GENERIC_MATH_LIBRARY_FLOAT_C_SOURCE = \
	absf.c \
	acosf.c \
	acoshf.c \
	acot2f.c \
	acotf.c \
	acothf.c \
	asinf.c \
	asinhf.c \
	atanf.c \
	atan2f.c \
	atanhf.c \
	ceilf.c \
	cosf.c \
	coshf.c \
	cotf.c \
	cothf.c \
	exp10f.c \
	exp2f.c \
	expf.c \
	fabsf.c \
	floorf.c \
	fmodf.c \
	fpclassifyf.c \
	frexpf.c \
	isfinitef.c \
	isinff.c \
	isnanf.c \
	isnormalf.c \
	ldexpf.c \
	log10f.c \
	log2f.c \
	logf.c \
	modff.c \
	powif.c \
	powf.c \
	roundf.c \
	rsqrtf.c \
	sinf.c \
	sinhf.c \
	sqrtf.c \
	tanf.c \
	tanhf.c \
	truncf.c

C_SOURCE += $(GENERIC_MATH_LIBRARY_FLOAT_C_SOURCE)


#-----------------------------------------------------------------------------
# Group GENERIC_MATH_LIBRARY_DOUBLE
#-----------------------------------------------------------------------------

GENERIC_MATH_LIBRARY_DOUBLE_C_SOURCE = \
	absd.c \
	acos.c \
	acosh.c \
	acot.c \
	acot2.c \
	acoth.c \
	asin.c \
	asinh.c \
	atan.c \
	atan2.c \
	atanh.c \
	ceil.c \
	cos.c \
	cosh.c \
	cot.c \
	coth.c \
	exp.c \
	exp10.c \
	exp2.c \
	fabs.c \
	floor.c \
	fmod.c \
	fpclassify.c \
	frexp.c \
	isfinite.c \
	isinf.c \
	isnan.c \
	isnormal.c \
	ldexp.c \
	log.c \
	log10.c \
	log2.c \
	modf.c \
	pow.c \
	powi.c \
	round.c \
	rsqrt.c \
	sin.c \
	sinh.c \
	sqrt.c \
	tan.c \
	tanh.c \
	trunc.c \
	signbit.c

C_SOURCE += $(GENERIC_MATH_LIBRARY_DOUBLE_C_SOURCE)


#-----------------------------------------------------------------------------
# Group GENERIC_MATH_FUNDAMENTAL_DOUBLE_IS_64
#-----------------------------------------------------------------------------

#-----------------------------------------------------------------------------
# Group GENERIC_MATH_FUNDAMENTAL_DOUBLE
#-----------------------------------------------------------------------------

GENERIC_MATH_FUNDAMENTAL_DOUBLE_C_SOURCE = \
	addd.c \
	cmpd.c \
	eqld.c \
	ged.c \
	gtd.c \
	led.c \
	ltd.c \
	neqld.c \
	cvtfd.c \
	divd.c \
	fixdi.c \
	fixdli.c \
	fixdlli.c \
	fixdu.c \
	fixdul.c \
	fixdull.c \
	fltid.c \
	fltlid.c \
	fltllid.c \
	fltud.c \
	fltuld.c \
	fltulld.c \
	frcaddd.c \
	frcdivd.c \
	frcmpyd.c \
	frcmpyd_div.c \
	mpyd.c \
	negd.c \
	renormd.c \
	subd.c

C_SOURCE += $(GENERIC_MATH_FUNDAMENTAL_DOUBLE_C_SOURCE)


#-----------------------------------------------------------------------------
# Group GENERIC_MATH_FUNDAMENTAL_FLOAT
#-----------------------------------------------------------------------------

GENERIC_MATH_FUNDAMENTAL_FLOAT_C_SOURCE = \
	addf.c \
	cmpf.c \
	eqlf.c \
	gef.c \
	gtf.c \
	lef.c \
	ltf.c \
	neqlf.c \
	cvtdf.c \
	divf.c \
	fixfi.c \
	fixfli.c \
	fixflli.c \
	fixfu.c \
	fixful.c \
	fixfull.c \
	fltif.c \
	fltlif.c \
	fltllif.c \
	fltuf.c \
	fltulf.c \
	fltullf.c \
	frcaddf.c \
	frcdivf.c \
	frcmpyf.c \
	frcmpyf_div.c \
	mpyf.c \
	negf.c \
	renormf.c \
	subf.c

C_SOURCE += $(GENERIC_MATH_FUNDAMENTAL_FLOAT_C_SOURCE)


#-----------------------------------------------------------------------------
# Group TSPA_CPP
#-----------------------------------------------------------------------------

#-----------------------------------------------------------------------------
# Group GENERIC_MATH_COMMON_64BIT
#-----------------------------------------------------------------------------

#-----------------------------------------------------------------------------
# Group GENERIC_MATH_COMMON_32BIT
#-----------------------------------------------------------------------------

#-----------------------------------------------------------------------------
# Group GENERIC_MATH_COMMON_FLOAT
#-----------------------------------------------------------------------------

#-----------------------------------------------------------------------------
# Group GENERIC_MATH_COMMON_DOUBLE
#-----------------------------------------------------------------------------

#-----------------------------------------------------------------------------
# Group TSPA_C99_COMPLEX
#-----------------------------------------------------------------------------

#-----------------------------------------------------------------------------
# Group EDG_GENERIC_C
#-----------------------------------------------------------------------------

#-----------------------------------------------------------------------------
# Group GENERIC_MATH_COMMON
#-----------------------------------------------------------------------------

#-----------------------------------------------------------------------------
# Group GENERIC_MATH_LIBRARY_COMMON
#-----------------------------------------------------------------------------
UNIVERSAL_FLAGS += -D__TI_USING_GENERIC_MATH

#-----------------------------------------------------------------------------
# Group EXCEPTIONS
#-----------------------------------------------------------------------------
ifeq ($(EXCEPTIONS),1)
CPP_FLAGS += --exceptions
endif


#-----------------------------------------------------------------------------
# Group STLPORT_CPP
#-----------------------------------------------------------------------------

STLPORT_CPP_CPP_SOURCE = \
	stlport/allocators.cpp \
	stlport/bitset.cpp \
	stlport/complex.cpp \
	stlport/complex_io.cpp \
	stlport/complex_trig.cpp \
	stlport/_ctype.cpp \
	stlport/dll_main.cpp \
	stlport/istream.cpp \
	stlport/ostream.cpp \
	stlport/sstream.cpp \
	stlport/string.cpp

CPP_SOURCE += $(STLPORT_CPP_CPP_SOURCE)


#-----------------------------------------------------------------------------
# Group FREEBSD_C99_COMPLEX
#-----------------------------------------------------------------------------
FREEBSD_C99_COMPLEX_C_FLAGS += --c99

#-----------------------------------------------------------------------------
# Group FREEBSD_C99_COMPLEX_COMMON
#-----------------------------------------------------------------------------

#-----------------------------------------------------------------------------
# Group OPENBSD_C99_COMPLEX
#-----------------------------------------------------------------------------
OPENBSD_C99_COMPLEX_C_FLAGS += --c99

OPENBSD_C99_COMPLEX_C_SOURCE = \
	s_clog.c \
	s_clogf.c \
	s_clogl.c \
	s_cpow.c \
	s_cpowf.c \
	s_cpowl.c

#-----------------------------------------------------------------------------
# Group V1
#-----------------------------------------------------------------------------
ifeq ($(V1),1)
UNIVERSAL_FLAGS += -v1
endif


#-----------------------------------------------------------------------------
# Group EDG_C99_COMPLEX_HELPER
#-----------------------------------------------------------------------------
EDG_C99_COMPLEX_HELPER_CPP_FLAGS += --building_runtime -DCHECKING=0

EDG_C99_COMPLEX_HELPER_CPP_SOURCE = \
	c99_complex.c

#-----------------------------------------------------------------------------
# Group CLASSIC_CPP_MATH_OVERLOADS
#-----------------------------------------------------------------------------

#-----------------------------------------------------------------------------
# Group GENERIC_EDG
#-----------------------------------------------------------------------------
GENERIC_EDG_CPP_FLAGS += --building_runtime -DCHECKING=0

GENERIC_EDG_CPP_SOURCE = \
	array_del.c \
	array_new.c \
	array_nodel.c \
	array_nonew.c \
	array_pdel.c \
	array_pnew.c \
	delete.c \
	delnothrow.c \
	dtor_list.c \
	error.c \
	guard.c \
	memzero.c \
	new.c \
	newhandler.c \
	newnothrow.c \
	placedel.c \
	placenew.c \
	pure_virt.c \
	rtti.c \
	set_new.c \
	typeinfo.c \
	vars.c \
	vec_cctor.c \
	vec_newdel.c \
	vla_alloc.c

#-----------------------------------------------------------------------------
# Group FREEBSD_C99_COMPLEX_64_BIT
#-----------------------------------------------------------------------------
FREEBSD_C99_COMPLEX_64_BIT_C_FLAGS += --c99

FREEBSD_C99_COMPLEX_64_BIT_C_SOURCE = \
	catrig.c \
	k_exp.c \
	s_ccosh.c \
	s_cexp.c \
	s_csinh.c \
	s_csqrt.c \
	s_ctanh.c \
	s_log1p.c \
	e_hypot.c \
	s_copysign.c

#-----------------------------------------------------------------------------
# Group FULL_PORTABLE_EH
#-----------------------------------------------------------------------------
ifeq ($(EXCEPTIONS),1)
FULL_PORTABLE_EH=1
endif

ifeq ($(FULL_PORTABLE_EH),1)
FULL_PORTABLE_EH_CPP_FLAGS += --building_runtime -DCHECKING=0

FULL_PORTABLE_EH_CPP_SOURCE = \
	eh_util.c \
	throw.c
endif


#-----------------------------------------------------------------------------
# Group GENERIC_C
#-----------------------------------------------------------------------------

GENERIC_C_C_SOURCE = \
	ecvt.c \
	exit.c \
	fcvt.c \
	memory.c \
	_bufread.c \
	_data_synch.c \
	_io_perm.c \
	_lock.c \
	_ltoa.c \
	_mutex.c \
	_printfi.c \
	_printfi_min.c \
	_printfi_nf.c \
	_pthread.c \
	_scanfi.c \
	_scanfi_min.c \
	_scanfi_nf.c \
	add_device.c \
	args_main.c \
	asctime.c \
	assert.c \
	atof.c \
	atoi.c \
	atol.c \
	atoll.c \
	bcmp.c \
	bcopy.c \
	bsearch.c \
	bzero.c \
	clearerr.c \
	clock.c \
	close.c \
	common_exit.c \
	ctime_.c \
	ctime64.c \
	ctype.c \
	defs.c \
	difftime.c \
	difftime64.c \
	fclose.c \
	feof.c \
	ferror.c \
	fflush.c \
	ffs.c \
	fgetc.c \
	fgetpos.c \
	fgets.c \
	fopen.c \
	fprintf.c \
	fputc.c \
	fputs.c \
	fread.c \
	fscanf.c \
	fseek.c \
	fsetpos.c \
	ftell.c \
	fwrite.c \
	getenv.c \
	getdevice.c \
	gmtime.c \
	gmtime64.c \
	index.c \
	isalnum.c \
	isalpha.c \
	isascii.c \
	iscntrl.c \
	isdigit.c \
	isgraph.c \
	islower.c \
	isprint.c \
	ispunct.c \
	isspace.c \
	isupper.c \
	isxdigit.c \
	localtim.c \
	localtim64.c \
	lseek.c \
	ltoa.c \
	memccpy.c \
	memchr.c \
	memcmp.c \
	memmov.c \
	memset.c \
	mktime.c \
	mktime64.c \
	multibyte.c \
	open.c \
	perror.c \
	printf.c \
	qsort.c \
	rand.c \
	read.c \
	remove.c \
	remove_device.c \
	rename.c \
	rewind.c \
	rindex.c \
	setbuf.c \
	setlocale.c \
	setvbuf.c \
	snprintf.c \
	sprintf.c \
	sscanf.c \
	strcasecmp.c \
	strcat.c \
	strchr.c \
	strcmp.c \
	strcoll.c \
	strcpy.c \
	strcspn.c \
	strdup.c \
	strerror.c \
	strftime.c \
	strlen.c \
	strncasecmp.c \
	strncat.c \
	strncmp.c \
	strncpy.c \
	strpbrk.c \
	strrchr.c \
	strspn.c \
	strstr.c \
	strtod.c \
	strtof.c \
	strtok.c \
	strtol.c \
	strtold.c \
	strtoll.c \
	strtoul.c \
	strtoull.c \
	strtoimax.c \
	strtoumax.c \
	strxfrm.c \
	time.c \
	time64.c \
	tmpfile.c \
	tmpnam.c \
	tmzone.c \
	toascii.c \
	tolower.c \
	toupper.c \
	hostclock.c \
	hostclose.c \
	hostgetenv.c \
	hostlseek.c \
	hostopen.c \
	hostread.c \
	hostrename.c \
	hosttime.c \
	hostunlink.c \
	hostwrite.c \
	trgmsg.c \
	ungetc.c \
	unlink.c \
	vfprintf.c \
	vprintf.c \
	vsnprintf.c \
	vsprintf.c \
	wctype.c \
	write.c \
	signal.c

C_SOURCE += $(GENERIC_C_C_SOURCE)


#-----------------------------------------------------------------------------
# Group LITTLE_ENDIAN
#-----------------------------------------------------------------------------
ifeq ($(LITTLE_ENDIAN),1)
UNIVERSAL_FLAGS += --endian=little
endif


#-----------------------------------------------------------------------------
# Group BIG_ENDIAN
#-----------------------------------------------------------------------------
ifeq ($(BIG_ENDIAN),1)
UNIVERSAL_FLAGS += --endian=big
endif


#-----------------------------------------------------------------------------
# Group FREEBSD_C99_COMPLEX_32_BIT
#-----------------------------------------------------------------------------
FREEBSD_C99_COMPLEX_32_BIT_C_FLAGS += --c99

FREEBSD_C99_COMPLEX_32_BIT_C_SOURCE = \
	catrigf.c \
	k_expf.c \
	s_carg.c \
	s_cargf.c \
	s_cargl.c \
	s_ccoshf.c \
	s_cexpf.c \
	s_cimag.c \
	s_cimagf.c \
	s_cimagl.c \
	s_conj.c \
	s_conjf.c \
	s_conjl.c \
	s_cproj.c \
	s_cprojf.c \
	s_cprojl.c \
	s_creal.c \
	s_crealf.c \
	s_creall.c \
	s_csinhf.c \
	s_csqrtf.c \
	s_ctanhf.c \
	w_cabs.c \
	w_cabsf.c \
	w_cabsl.c \
	s_log1pf.c \
	e_hypotf.c \
	s_copysignf.c

#-----------------------------------------------------------------------------
# Group V3
#-----------------------------------------------------------------------------
ifeq ($(V3),1)
UNIVERSAL_FLAGS += -v3
endif


#-----------------------------------------------------------------------------
# Group STLPORT_LOCALE
#-----------------------------------------------------------------------------
STLPORT_LOCALE_CPP_FLAGS += -O3 --inline_recursion_limit=12

STLPORT_LOCALE_CPP_SOURCE = \
	stlport/unified_locale.cpp

#-----------------------------------------------------------------------------
# Group EDG_CPP_SUPPLEMENTAL
#-----------------------------------------------------------------------------
EDG_CPP_SUPPLEMENTAL_CPP_FLAGS += --building_runtime -DCHECKING=0

EDG_CPP_SUPPLEMENTAL_CPP_SOURCE = \
	exception.c \
	bad_alloc.c

#-----------------------------------------------------------------------------
# Group V2
#-----------------------------------------------------------------------------
ifeq ($(V2),1)
UNIVERSAL_FLAGS += -v2
endif


#-----------------------------------------------------------------------------
# Group CLASSIC_MATH_LIBRARY_INTEGER
#-----------------------------------------------------------------------------

CLASSIC_MATH_LIBRARY_INTEGER_C_SOURCE = \
	abs.c \
	labs.c \
	llabs.c \
	imaxabs.c \
	imaxdiv.c

C_SOURCE += $(CLASSIC_MATH_LIBRARY_INTEGER_C_SOURCE)


#-----------------------------------------------------------------------------
# Group GENERIC_OPTIONS
#-----------------------------------------------------------------------------
CPP_FLAGS += --rtti -fg
ASM_FLAGS += 
UNIVERSAL_FLAGS += -c --ti_lib --keep_unneeded_types=false --diag_warning=225 --quiet -O4

#-----------------------------------------------------------------------------
# Group GENERIC_MATH_LIBRARY_INTEGER
#-----------------------------------------------------------------------------

GENERIC_MATH_LIBRARY_INTEGER_C_SOURCE = \
	div.c \
	ldiv.c \
	lldiv.c

C_SOURCE += $(GENERIC_MATH_LIBRARY_INTEGER_C_SOURCE)


#-----------------------------------------------------------------------------
# Group EABI
#-----------------------------------------------------------------------------
EABI_CPP_FLAGS += --building_runtime -DCHECKING=0

EABI_CPP_SOURCE = \
	decode.c

#-----------------------------------------------------------------------------
# Group CLASSIC_ERRNO
#-----------------------------------------------------------------------------

CLASSIC_ERRNO_C_SOURCE = \
	errno.c

C_SOURCE += $(CLASSIC_ERRNO_C_SOURCE)


#-----------------------------------------------------------------------------
# Group BASIC_WCHAR
#-----------------------------------------------------------------------------

BASIC_WCHAR_C_SOURCE = \
	wctob.c \
	fgetwc.c \
	wcslen.c \
	wmemchr.c \
	wmemcmp.c \
	wmemcpy.c \
	wmemmove.c \
	wmemset.c \
	wcscmp.c \
	wcsncmp.c \
	wcsncpy.c \
	ascii.c

C_SOURCE += $(BASIC_WCHAR_C_SOURCE)


#-----------------------------------------------------------------------------
# Group TSPA_COMPLEX_HEADERS
#-----------------------------------------------------------------------------


EABI_CPP_OBJS_1 = $(patsubst %.c,$(OBJ)/%.c.obj,$(EABI_CPP_SOURCE))
$(EABI_CPP_OBJS_1): $(OBJ)/%.c.obj: %.c
	$(CC) $< $(EXTRA_FLAGS) $(UNIVERSAL_FLAGS) $(EABI_FLAGS) $(CPP_FLAGS) $(EABI_CPP_FLAGS) -I$(INC) -fe $@ -fs $(OBJ) -ft $(OBJ) -ppa -ppd=$(OBJ)/$(basename $(@F)).pp
	@$(CP_CMD) $(OBJ)/$(basename $(@F)).pp $(OBJ)/$(basename $(@F)).P
	@$(SED_CMD) -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\$$//' \
	-e '/^$$/ d' -e 's/$$/ :/' < $(OBJ)/$(basename $(@F)).pp >> $(OBJ)/$(basename $(@F)).P
	@$(RM_CMD) -f $(OBJ)/$(basename $(@F)).pp

EDG_CPP_SUPPLEMENTAL_CPP_OBJS_2 = $(patsubst %.c,$(OBJ)/%.c.obj,$(EDG_CPP_SUPPLEMENTAL_CPP_SOURCE))
$(EDG_CPP_SUPPLEMENTAL_CPP_OBJS_2): $(OBJ)/%.c.obj: %.c
	$(CC) $< $(EXTRA_FLAGS) $(UNIVERSAL_FLAGS) $(EDG_CPP_SUPPLEMENTAL_FLAGS) $(CPP_FLAGS) $(EDG_CPP_SUPPLEMENTAL_CPP_FLAGS) -I$(INC) -fe $@ -fs $(OBJ) -ft $(OBJ) -ppa -ppd=$(OBJ)/$(basename $(@F)).pp
	@$(CP_CMD) $(OBJ)/$(basename $(@F)).pp $(OBJ)/$(basename $(@F)).P
	@$(SED_CMD) -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\$$//' \
	-e '/^$$/ d' -e 's/$$/ :/' < $(OBJ)/$(basename $(@F)).pp >> $(OBJ)/$(basename $(@F)).P
	@$(RM_CMD) -f $(OBJ)/$(basename $(@F)).pp

STLPORT_LOCALE_CPP_OBJS_3 = $(patsubst %.cpp,$(OBJ)/%.cpp.obj,$(STLPORT_LOCALE_CPP_SOURCE))
$(STLPORT_LOCALE_CPP_OBJS_3): $(OBJ)/%.cpp.obj: %.cpp
	$(CC) $< $(EXTRA_FLAGS) $(UNIVERSAL_FLAGS) $(STLPORT_LOCALE_FLAGS) $(CPP_FLAGS) $(STLPORT_LOCALE_CPP_FLAGS) -I$(INC) -fe $@ -fs $(OBJ) -ft $(OBJ) -ppa -ppd=$(OBJ)/$(basename $(@F)).pp
	@$(CP_CMD) $(OBJ)/$(basename $(@F)).pp $(OBJ)/$(basename $(@F)).P
	@$(SED_CMD) -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\$$//' \
	-e '/^$$/ d' -e 's/$$/ :/' < $(OBJ)/$(basename $(@F)).pp >> $(OBJ)/$(basename $(@F)).P
	@$(RM_CMD) -f $(OBJ)/$(basename $(@F)).pp

FREEBSD_C99_COMPLEX_32_BIT_C_OBJS_4 = $(patsubst %.c,$(OBJ)/%.c.obj,$(FREEBSD_C99_COMPLEX_32_BIT_C_SOURCE))
$(FREEBSD_C99_COMPLEX_32_BIT_C_OBJS_4): $(OBJ)/%.c.obj: %.c
	$(CC) $< $(EXTRA_FLAGS) $(UNIVERSAL_FLAGS) $(FREEBSD_C99_COMPLEX_32_BIT_FLAGS) $(C_FLAGS) $(FREEBSD_C99_COMPLEX_32_BIT_C_FLAGS) -I$(INC) -fe $@ -fs $(OBJ) -ft $(OBJ) -ppa -ppd=$(OBJ)/$(basename $(@F)).pp
	@$(CP_CMD) $(OBJ)/$(basename $(@F)).pp $(OBJ)/$(basename $(@F)).P
	@$(SED_CMD) -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\$$//' \
	-e '/^$$/ d' -e 's/$$/ :/' < $(OBJ)/$(basename $(@F)).pp >> $(OBJ)/$(basename $(@F)).P
	@$(RM_CMD) -f $(OBJ)/$(basename $(@F)).pp

FULL_PORTABLE_EH_CPP_OBJS_5 = $(patsubst %.c,$(OBJ)/%.c.obj,$(FULL_PORTABLE_EH_CPP_SOURCE))
$(FULL_PORTABLE_EH_CPP_OBJS_5): $(OBJ)/%.c.obj: %.c
	$(CC) $< $(EXTRA_FLAGS) $(UNIVERSAL_FLAGS) $(FULL_PORTABLE_EH_FLAGS) $(CPP_FLAGS) $(FULL_PORTABLE_EH_CPP_FLAGS) -I$(INC) -fe $@ -fs $(OBJ) -ft $(OBJ) -ppa -ppd=$(OBJ)/$(basename $(@F)).pp
	@$(CP_CMD) $(OBJ)/$(basename $(@F)).pp $(OBJ)/$(basename $(@F)).P
	@$(SED_CMD) -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\$$//' \
	-e '/^$$/ d' -e 's/$$/ :/' < $(OBJ)/$(basename $(@F)).pp >> $(OBJ)/$(basename $(@F)).P
	@$(RM_CMD) -f $(OBJ)/$(basename $(@F)).pp

FREEBSD_C99_COMPLEX_64_BIT_C_OBJS_6 = $(patsubst %.c,$(OBJ)/%.c.obj,$(FREEBSD_C99_COMPLEX_64_BIT_C_SOURCE))
$(FREEBSD_C99_COMPLEX_64_BIT_C_OBJS_6): $(OBJ)/%.c.obj: %.c
	$(CC) $< $(EXTRA_FLAGS) $(UNIVERSAL_FLAGS) $(FREEBSD_C99_COMPLEX_64_BIT_FLAGS) $(C_FLAGS) $(FREEBSD_C99_COMPLEX_64_BIT_C_FLAGS) -I$(INC) -fe $@ -fs $(OBJ) -ft $(OBJ) -ppa -ppd=$(OBJ)/$(basename $(@F)).pp
	@$(CP_CMD) $(OBJ)/$(basename $(@F)).pp $(OBJ)/$(basename $(@F)).P
	@$(SED_CMD) -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\$$//' \
	-e '/^$$/ d' -e 's/$$/ :/' < $(OBJ)/$(basename $(@F)).pp >> $(OBJ)/$(basename $(@F)).P
	@$(RM_CMD) -f $(OBJ)/$(basename $(@F)).pp

GENERIC_EDG_CPP_OBJS_7 = $(patsubst %.c,$(OBJ)/%.c.obj,$(GENERIC_EDG_CPP_SOURCE))
$(GENERIC_EDG_CPP_OBJS_7): $(OBJ)/%.c.obj: %.c
	$(CC) $< $(EXTRA_FLAGS) $(UNIVERSAL_FLAGS) $(GENERIC_EDG_FLAGS) $(CPP_FLAGS) $(GENERIC_EDG_CPP_FLAGS) -I$(INC) -fe $@ -fs $(OBJ) -ft $(OBJ) -ppa -ppd=$(OBJ)/$(basename $(@F)).pp
	@$(CP_CMD) $(OBJ)/$(basename $(@F)).pp $(OBJ)/$(basename $(@F)).P
	@$(SED_CMD) -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\$$//' \
	-e '/^$$/ d' -e 's/$$/ :/' < $(OBJ)/$(basename $(@F)).pp >> $(OBJ)/$(basename $(@F)).P
	@$(RM_CMD) -f $(OBJ)/$(basename $(@F)).pp

EDG_C99_COMPLEX_HELPER_CPP_OBJS_8 = $(patsubst %.c,$(OBJ)/%.c.obj,$(EDG_C99_COMPLEX_HELPER_CPP_SOURCE))
$(EDG_C99_COMPLEX_HELPER_CPP_OBJS_8): $(OBJ)/%.c.obj: %.c
	$(CC) $< $(EXTRA_FLAGS) $(UNIVERSAL_FLAGS) $(EDG_C99_COMPLEX_HELPER_FLAGS) $(CPP_FLAGS) $(EDG_C99_COMPLEX_HELPER_CPP_FLAGS) -I$(INC) -fe $@ -fs $(OBJ) -ft $(OBJ) -ppa -ppd=$(OBJ)/$(basename $(@F)).pp
	@$(CP_CMD) $(OBJ)/$(basename $(@F)).pp $(OBJ)/$(basename $(@F)).P
	@$(SED_CMD) -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\$$//' \
	-e '/^$$/ d' -e 's/$$/ :/' < $(OBJ)/$(basename $(@F)).pp >> $(OBJ)/$(basename $(@F)).P
	@$(RM_CMD) -f $(OBJ)/$(basename $(@F)).pp

OPENBSD_C99_COMPLEX_C_OBJS_9 = $(patsubst %.c,$(OBJ)/%.c.obj,$(OPENBSD_C99_COMPLEX_C_SOURCE))
$(OPENBSD_C99_COMPLEX_C_OBJS_9): $(OBJ)/%.c.obj: %.c
	$(CC) $< $(EXTRA_FLAGS) $(UNIVERSAL_FLAGS) $(OPENBSD_C99_COMPLEX_FLAGS) $(C_FLAGS) $(OPENBSD_C99_COMPLEX_C_FLAGS) -I$(INC) -fe $@ -fs $(OBJ) -ft $(OBJ) -ppa -ppd=$(OBJ)/$(basename $(@F)).pp
	@$(CP_CMD) $(OBJ)/$(basename $(@F)).pp $(OBJ)/$(basename $(@F)).P
	@$(SED_CMD) -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\$$//' \
	-e '/^$$/ d' -e 's/$$/ :/' < $(OBJ)/$(basename $(@F)).pp >> $(OBJ)/$(basename $(@F)).P
	@$(RM_CMD) -f $(OBJ)/$(basename $(@F)).pp

ASM_OBJS_10 = $(patsubst %.asm,$(OBJ)/%.asm.obj,$(ASM_SOURCE))
$(ASM_OBJS_10): $(OBJ)/%.asm.obj: %.asm
	$(CC) $< $(EXTRA_FLAGS) $(STANDARD_FLAGS) $(EXTRA_FLAGS) $(UNIVERSAL_FLAGS) $(UNIVERSAL_FLAGS) $(ASM_FLAGS) -I$(INC) -fe $@ -fs $(OBJ) -ft $(OBJ)
	$(CC) $< $(EXTRA_FLAGS) $(STANDARD_FLAGS) $(EXTRA_FLAGS) $(UNIVERSAL_FLAGS) $(UNIVERSAL_FLAGS) $(ASM_FLAGS) -I$(INC) -fr $(OBJ) -fs $(OBJ) -ft $(OBJ) --asm_dependency=$(OBJ)/$(basename $(@F)).pp
	@$(CP_CMD) $(OBJ)/$(basename $(@F)).pp $(OBJ)/$(basename $(@F)).P
	@$(SED_CMD) -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\$$//' \
	-e '/^$$/ d' -e 's/$$/ :/' < $(OBJ)/$(basename $(@F)).pp >> $(OBJ)/$(basename $(@F)).P
	@$(RM_CMD) -f $(OBJ)/$(basename $(@F)).pp

CPP_OBJS_11 = $(patsubst %.cpp,$(OBJ)/%.cpp.obj,$(CPP_SOURCE))
$(CPP_OBJS_11): $(OBJ)/%.cpp.obj: %.cpp
	$(CC) $< $(EXTRA_FLAGS) $(STANDARD_FLAGS) $(EXTRA_FLAGS) $(UNIVERSAL_FLAGS) $(UNIVERSAL_FLAGS) $(CPP_FLAGS) -I$(INC) -fe $@ -fs $(OBJ) -ft $(OBJ) -ppa -ppd=$(OBJ)/$(basename $(@F)).pp
	@$(CP_CMD) $(OBJ)/$(basename $(@F)).pp $(OBJ)/$(basename $(@F)).P
	@$(SED_CMD) -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\$$//' \
	-e '/^$$/ d' -e 's/$$/ :/' < $(OBJ)/$(basename $(@F)).pp >> $(OBJ)/$(basename $(@F)).P
	@$(RM_CMD) -f $(OBJ)/$(basename $(@F)).pp

C_OBJS_12 = $(patsubst %.c,$(OBJ)/%.c.obj,$(C_SOURCE))
$(C_OBJS_12): $(OBJ)/%.c.obj: %.c
	$(CC) $< $(EXTRA_FLAGS) $(STANDARD_FLAGS) $(EXTRA_FLAGS) $(UNIVERSAL_FLAGS) $(UNIVERSAL_FLAGS) $(C_FLAGS) -I$(INC) -fe $@ -fs $(OBJ) -ft $(OBJ) -ppa -ppd=$(OBJ)/$(basename $(@F)).pp
	@$(CP_CMD) $(OBJ)/$(basename $(@F)).pp $(OBJ)/$(basename $(@F)).P
	@$(SED_CMD) -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\$$//' \
	-e '/^$$/ d' -e 's/$$/ :/' < $(OBJ)/$(basename $(@F)).pp >> $(OBJ)/$(basename $(@F)).P
	@$(RM_CMD) -f $(OBJ)/$(basename $(@F)).pp

ALL_OBJS = $(EABI_CPP_OBJS_1) $(EDG_CPP_SUPPLEMENTAL_CPP_OBJS_2) $(STLPORT_LOCALE_CPP_OBJS_3) $(FREEBSD_C99_COMPLEX_32_BIT_C_OBJS_4) $(FULL_PORTABLE_EH_CPP_OBJS_5) $(FREEBSD_C99_COMPLEX_64_BIT_C_OBJS_6) $(GENERIC_EDG_CPP_OBJS_7) $(EDG_C99_COMPLEX_HELPER_CPP_OBJS_8) $(OPENBSD_C99_COMPLEX_C_OBJS_9) $(ASM_OBJS_10) $(CPP_OBJS_11) $(C_OBJS_12)
RELATIVE_EABI_CPP_OBJS_1 := $(foreach obj,$(EABI_CPP_OBJS_1),$(subst $(OBJ)/,,$(obj)))
RELATIVE_EDG_CPP_SUPPLEMENTAL_CPP_OBJS_2 := $(foreach obj,$(EDG_CPP_SUPPLEMENTAL_CPP_OBJS_2),$(subst $(OBJ)/,,$(obj)))
RELATIVE_STLPORT_LOCALE_CPP_OBJS_3 := $(foreach obj,$(STLPORT_LOCALE_CPP_OBJS_3),$(subst $(OBJ)/,,$(obj)))
RELATIVE_FREEBSD_C99_COMPLEX_32_BIT_C_OBJS_4 := $(foreach obj,$(FREEBSD_C99_COMPLEX_32_BIT_C_OBJS_4),$(subst $(OBJ)/,,$(obj)))
RELATIVE_FULL_PORTABLE_EH_CPP_OBJS_5 := $(foreach obj,$(FULL_PORTABLE_EH_CPP_OBJS_5),$(subst $(OBJ)/,,$(obj)))
RELATIVE_FREEBSD_C99_COMPLEX_64_BIT_C_OBJS_6 := $(foreach obj,$(FREEBSD_C99_COMPLEX_64_BIT_C_OBJS_6),$(subst $(OBJ)/,,$(obj)))
RELATIVE_GENERIC_EDG_CPP_OBJS_7 := $(foreach obj,$(GENERIC_EDG_CPP_OBJS_7),$(subst $(OBJ)/,,$(obj)))
RELATIVE_EDG_C99_COMPLEX_HELPER_CPP_OBJS_8 := $(foreach obj,$(EDG_C99_COMPLEX_HELPER_CPP_OBJS_8),$(subst $(OBJ)/,,$(obj)))
RELATIVE_OPENBSD_C99_COMPLEX_C_OBJS_9 := $(foreach obj,$(OPENBSD_C99_COMPLEX_C_OBJS_9),$(subst $(OBJ)/,,$(obj)))
RELATIVE_ASM_OBJS_10 := $(foreach obj,$(ASM_OBJS_10),$(subst $(OBJ)/,,$(obj)))
RELATIVE_CPP_OBJS_11 := $(foreach obj,$(CPP_OBJS_11),$(subst $(OBJ)/,,$(obj)))
RELATIVE_C_OBJS_12 := $(foreach obj,$(C_OBJS_12),$(subst $(OBJ)/,,$(obj)))

-include $(ALL_OBJS:.obj=.P)

library: $(ALL_OBJS)
	@echo "Creating library $(LIB)"
	$(CD) $(OBJ); $(AR) -qa $(LIB) $(RELATIVE_EABI_CPP_OBJS_1)
	$(CD) $(OBJ); $(AR) -qa $(LIB) $(RELATIVE_EDG_CPP_SUPPLEMENTAL_CPP_OBJS_2)
	$(CD) $(OBJ); $(AR) -qa $(LIB) $(RELATIVE_STLPORT_LOCALE_CPP_OBJS_3)
	$(CD) $(OBJ); $(AR) -qa $(LIB) $(RELATIVE_FREEBSD_C99_COMPLEX_32_BIT_C_OBJS_4)
	$(CD) $(OBJ); $(AR) -qa $(LIB) $(RELATIVE_FULL_PORTABLE_EH_CPP_OBJS_5)
	$(CD) $(OBJ); $(AR) -qa $(LIB) $(RELATIVE_FREEBSD_C99_COMPLEX_64_BIT_C_OBJS_6)
	$(CD) $(OBJ); $(AR) -qa $(LIB) $(RELATIVE_GENERIC_EDG_CPP_OBJS_7)
	$(CD) $(OBJ); $(AR) -qa $(LIB) $(RELATIVE_EDG_C99_COMPLEX_HELPER_CPP_OBJS_8)
	$(CD) $(OBJ); $(AR) -qa $(LIB) $(RELATIVE_OPENBSD_C99_COMPLEX_C_OBJS_9)
	$(CD) $(OBJ); $(AR) -qa $(LIB) $(RELATIVE_ASM_OBJS_10)
	$(CD) $(OBJ); $(AR) -qa $(LIB) $(RELATIVE_CPP_OBJS_11)
	$(CD) $(OBJ); $(AR) -qa $(LIB) $(RELATIVE_C_OBJS_12)

info:
	@echo EABI_CPP_OBJS_1 $(EABI_CPP_OBJS_1)
	@echo EDG_CPP_SUPPLEMENTAL_CPP_OBJS_2 $(EDG_CPP_SUPPLEMENTAL_CPP_OBJS_2)
	@echo STLPORT_LOCALE_CPP_OBJS_3 $(STLPORT_LOCALE_CPP_OBJS_3)
	@echo FREEBSD_C99_COMPLEX_32_BIT_C_OBJS_4 $(FREEBSD_C99_COMPLEX_32_BIT_C_OBJS_4)
	@echo FULL_PORTABLE_EH_CPP_OBJS_5 $(FULL_PORTABLE_EH_CPP_OBJS_5)
	@echo FREEBSD_C99_COMPLEX_64_BIT_C_OBJS_6 $(FREEBSD_C99_COMPLEX_64_BIT_C_OBJS_6)
	@echo GENERIC_EDG_CPP_OBJS_7 $(GENERIC_EDG_CPP_OBJS_7)
	@echo EDG_C99_COMPLEX_HELPER_CPP_OBJS_8 $(EDG_C99_COMPLEX_HELPER_CPP_OBJS_8)
	@echo OPENBSD_C99_COMPLEX_C_OBJS_9 $(OPENBSD_C99_COMPLEX_C_OBJS_9)
	@echo ASM_OBJS_10 $(ASM_OBJS_10)
	@echo CPP_OBJS_11 $(CPP_OBJS_11)
	@echo C_OBJS_12 $(C_OBJS_12)
	@echo ASM_FLAGS $(ASM_FLAGS)
	@echo CPP_FLAGS $(CPP_FLAGS)
	@echo C_FLAGS $(C_FLAGS)
	@echo EABI_CPP_FLAGS $(EABI_CPP_FLAGS)
	@echo EABI_FLAGS $(EABI_FLAGS)
	@echo EDG_C99_COMPLEX_HELPER_CPP_FLAGS $(EDG_C99_COMPLEX_HELPER_CPP_FLAGS)
	@echo EDG_C99_COMPLEX_HELPER_FLAGS $(EDG_C99_COMPLEX_HELPER_FLAGS)
	@echo EDG_CPP_SUPPLEMENTAL_CPP_FLAGS $(EDG_CPP_SUPPLEMENTAL_CPP_FLAGS)
	@echo EDG_CPP_SUPPLEMENTAL_FLAGS $(EDG_CPP_SUPPLEMENTAL_FLAGS)
	@echo EXTRA_FLAGS $(EXTRA_FLAGS)
	@echo FREEBSD_C99_COMPLEX_32_BIT_C_FLAGS $(FREEBSD_C99_COMPLEX_32_BIT_C_FLAGS)
	@echo FREEBSD_C99_COMPLEX_32_BIT_FLAGS $(FREEBSD_C99_COMPLEX_32_BIT_FLAGS)
	@echo FREEBSD_C99_COMPLEX_64_BIT_C_FLAGS $(FREEBSD_C99_COMPLEX_64_BIT_C_FLAGS)
	@echo FREEBSD_C99_COMPLEX_64_BIT_FLAGS $(FREEBSD_C99_COMPLEX_64_BIT_FLAGS)
	@echo FULL_PORTABLE_EH_CPP_FLAGS $(FULL_PORTABLE_EH_CPP_FLAGS)
	@echo FULL_PORTABLE_EH_FLAGS $(FULL_PORTABLE_EH_FLAGS)
	@echo GENERIC_EDG_CPP_FLAGS $(GENERIC_EDG_CPP_FLAGS)
	@echo GENERIC_EDG_FLAGS $(GENERIC_EDG_FLAGS)
	@echo OPENBSD_C99_COMPLEX_C_FLAGS $(OPENBSD_C99_COMPLEX_C_FLAGS)
	@echo OPENBSD_C99_COMPLEX_FLAGS $(OPENBSD_C99_COMPLEX_FLAGS)
	@echo STANDARD_FLAGS $(STANDARD_FLAGS)
	@echo STLPORT_LOCALE_CPP_FLAGS $(STLPORT_LOCALE_CPP_FLAGS)
	@echo STLPORT_LOCALE_FLAGS $(STLPORT_LOCALE_FLAGS)
	@echo UNIVERSAL_FLAGS $(UNIVERSAL_FLAGS)
