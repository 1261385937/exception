#pragma once
#ifndef PERSONAL_EXCEPTION_HAS_CODE_
#define PERSONAL_EXCEPTION_HAS_CODE_

#include <stdexcept>
#include <sstream>
#include <string>

#define EXCEPTION_SRC strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__
#define EXCEPTION_LINE __LINE__

namespace except
{
	class exception_base :public std::exception
	{
	public:
		virtual int getErrorCode() const { return 0; };
		virtual void rethrow() const {};
		virtual ~exception_base() {}
	};

#define DECLARE_EXCEPTION(class_name)	\
	class class_name : public exception_base											\
	{																					\
	public:																				\
		class_name(const std::string& error_msg, int error_code,						\
			const std::string& src_name, int src_line)									\
			:error_msg_(error_msg),error_code_(error_code)								\
		{																				\
			std::ostringstream oss;														\
			oss << "Exception occured at "												\
				<< src_name << ":" << src_line << ". " << error_msg_;					\
			error_msg_ = oss.str();														\
		}																				\
		class_name(const std::string& error_msg, int error_code)						\
			:error_msg_(error_msg), error_code_(error_code) {}							\
		class_name(const std::string& error_msg)										\
			:error_msg_(error_msg), error_code_(0) {}									\
		int getErrorCode() const { return error_code_; }								\
		const char* what() const noexcept { return error_msg_.c_str(); }				\
		void rethrow() const{ throw *this; }											\
	private:																			\
		int error_code_;																\
		std::string error_msg_;															\
	}

	constexpr int BASE_ERROR = -200000000;

	//define your own exception here...........................

	constexpr int COMMON = BASE_ERROR - 1;
	DECLARE_EXCEPTION(CommonException);
	constexpr int SQL_EMPTY = BASE_ERROR - 2;
	DECLARE_EXCEPTION(SqlEmptyException);
	constexpr int SQL_ERROR = BASE_ERROR - 3;
	DECLARE_EXCEPTION(SqlErrorException);
	//DECLARE_EXCEPTION(NotFoundRServerException);//CSErrorNotFoundRServer = -2146435068
	//DECLARE_EXCEPTION(NotFoundTServerException);//CSErrorNotFoundTServer = -2146435067
	//DECLARE_EXCEPTION(NoRecordPlanException);//CSErrorNotFoundRecordPlan = -2146435066
	//DECLARE_EXCEPTION(TransmitterServerUnavailableException);//CSErrorTransmitterServerUnavailable = -2146435064
	//DECLARE_EXCEPTION(AlreadyExistedException);//CSErrorAlreadyExisted = -2146435063
	//DECLARE_EXCEPTION(OperationNotExistException);//CSErrorOperationNotExist = -2146435062
	//DECLARE_EXCEPTION(ServerUnavailableException);//CSErrorServerUnavailable = -2146435061
	//DECLARE_EXCEPTION(AttatchCameraToServerException);//CSErrorAttatchCameraToServer = -2146435060
	//DECLARE_EXCEPTION(LoginDeviceException);//CSErrorLoginDevice = -2146435059
	//DECLARE_EXCEPTION(RemoveCameraException);//CSErrorRemoveCamera = -2146435058
	//DECLARE_EXCEPTION(AssignRecordPlanToCameraException);//CSErrorAssignRecordPlanToCamera = -2146435057
	//DECLARE_EXCEPTION(RemoveRecordPlanException);//CSErrorRemoveRecordPlan = -2146435056
	//DECLARE_EXCEPTION(AppliedRecordException);//CSErrorAppliedRecord = -2146435055
	//DECLARE_EXCEPTION(CameraMaximumException);//CSErrorCameraMaximum = -2146435054
	//DECLARE_EXCEPTION(CheckDongleFailException);//CSErrorCheckDongleFail = -2146435053;
	//DECLARE_EXCEPTION(MapSaveImageException);//CSErrorEMapSaveImage = -2146435052;
	//DECLARE_EXCEPTION(FolderMaximumException);//CSErrorFolderMaximum = -2146435051;
	//DECLARE_EXCEPTION(NotFindObjectException);//CSErrorNotFindObject = -2146435050;
	//DECLARE_EXCEPTION(NotLoginException);//CSErrorNotLogin = -2146435049;
	//DECLARE_EXCEPTION(SqlException);//CSErrorSqlException = -2146435048;
	//DECLARE_EXCEPTION(AddCameraException);//CSErrorAddCamera = -2146435047;
	//DECLARE_EXCEPTION(InvalidParameterException);//CSErrorInvalidParameter = -2146435046;
	//DECLARE_EXCEPTION(MemoryAllocateException);//CSErrorMemoryAllocate = -2146435045;
	//DECLARE_EXCEPTION(BadRequestException);//CSErrorBadRequest = -2146435044;
	//DECLARE_EXCEPTION(RequestFailedException);//CSErrorRequestFailed = -2146435043;
	//DECLARE_EXCEPTION(PermissionDeiedException);//CSErrorPermissionDeied = -2146435042;
	//DECLARE_EXCEPTION(InvalidSessionException);//CSErrorInvalidSession = -2146435041;
	//DECLARE_EXCEPTION(RecordPlanTimeSegmentException);//CSErrorRecordPlanTimeSegment = -2146435040;
	//DECLARE_EXCEPTION(NVRChannelMaximumException);//CSErrorNVRChannelMaximum = -2146435039;
	//DECLARE_EXCEPTION(PTZControlOccupiedException);//CSErrorPTZControlOccupied = -2146435038;
	//DECLARE_EXCEPTION(CameraOperationFailedException);//CSErrorCameraOperationFailed = -2146435037;
	//DECLARE_EXCEPTION(ViskingNVRSDKException);//CSErrorViskingNVRSDK = -2146435036;
	//DECLARE_EXCEPTION(GMISDKException);//CSErrorGMISDK = -2146435035;
	//DECLARE_EXCEPTION(ViskingNVRSDKUnsupportedException);//CSErrorViskingNVRSDKUnsupported = -2146435034;
	//DECLARE_EXCEPTION(SysFileOperationFailedException);//CSErrorSysFileOperationFailed = -2146435033;
	//DECLARE_EXCEPTION(GB28181SDKException);//CSErrorGB28181SDK = -2146435032;
	//DECLARE_EXCEPTION(ONVIFSDKException);//CSErrorONVIFSDK = -2146435031;
	//DECLARE_EXCEPTION(RemoveServerAttatchedIPCException);//CSErrorRemoveServerAttatchedIPC = -2146435030;
	//DECLARE_EXCEPTION(RemoveServerAttatchedIPCIPCException);//CSErrorRemoveServerAttatchedIPC = -2146435030;
	//DECLARE_EXCEPTION(OnvifSDKUnsupportedException);//CSErrorOnvifSDKUnsupported = -2146435029;
	//DECLARE_EXCEPTION(HIKNVRSDKUnsupportedException);//CSErrorHIKNVRSDKUnsupported = -2146435028;
	//DECLARE_EXCEPTION(DongleExpiredException);//CSErrorDongleExpired = -2146435027;
	//DECLARE_EXCEPTION(AlarmEmailNotConfiguredException);//CSErrorAlarmEmailNotConfigured = -2146435026;
	//DECLARE_EXCEPTION(DongleVideoDiagChannelException);//CSErrorDongleVideoDiagChannel = -2146435025;
	//DECLARE_EXCEPTION(UnsupportedException);//CSErrorUnsupported = -2146435024;
	//DECLARE_EXCEPTION(HikNVRSDKException); //CSErrorHikNVRSDK = -2146435023;
	//DECLARE_EXCEPTION(JMNVRSDKException);//CSErrorJMNVRSDK = -2146435022;
	//DECLARE_EXCEPTION(SearchResultLeftException);//CSSearchResultLeft = -2146435021;
	//DECLARE_EXCEPTION(RequestTimeoutException);//CSErrorRequestTimeout = -2146434992;
	//DECLARE_EXCEPTION(GMISDKConnectedFailedException);//CSErrorGMISDKConnectedFailed = -2146434991;
	//DECLARE_EXCEPTION(DevErrNotSupportException);//DevErrNotSupport = -2145434990;
	//DECLARE_EXCEPTION(DevErrInvalidParamException);//DevErrInvalidParam = -2145434989;
	//DECLARE_EXCEPTION(NetworkException);//CSErrorNetworkException = -2145434988;
	//DECLARE_EXCEPTION(HaveLoginedException);//CSErrorHaveLogined = -2145434987;
	//DECLARE_EXCEPTION(LoginingException);//CSErrorLogining = -2145434986;
	//DECLARE_EXCEPTION(AssignCameraToDiagPlanException);//CSErrorAssignCameraToDiagPlan = -2145434985;
	//DECLARE_EXCEPTION(RemoveCameraFromDiagPlanException);//CSErrorRemoveCameraFromDiagPlan = -2145434984;
	//DECLARE_EXCEPTION(RemoveDiagPlanException);//CSErrorRemoveDiagPlan = -2145434983;
	//DECLARE_EXCEPTION(AppliedDiagException);//CSErrorAppliedDiag = -2145434982;
	//DECLARE_EXCEPTION(GBProxyNotExistException);//CSErrorGBProxyNotExist = -2145434981;
	//DECLARE_EXCEPTION(OpenSerialPortException);//CSErrorOpenSerialPort = -2145434980;
	//DECLARE_EXCEPTION(I8HSDKException);//CSErrorI8HSDK = -2145434979;
}

#endif