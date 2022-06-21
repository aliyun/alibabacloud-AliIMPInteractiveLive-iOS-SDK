Pod::Spec.new do |s|
  s.name         = "AliStandardLiveRoomBundle"
  s.version      = "2.0.0-rc2"
  s.summary      = "AliStandardLiveRoomBundle."
  s.description  = <<-DESC
                   It's an SDK for aliyun interactive live, which implement by Objective-C.
                   DESC
  s.homepage     = "https://github.com/aliyun/alibabacloud-AliIMPInteractiveLive-iOS-SDK"
  s.license      = { :type => "MIT", :file => "LICENSE" }
  s.author       = { "aliyunvideo" => "weihe.whq@alibaba-inc.com"}
  s.platform     = :ios
  s.platform     = :ios, "10.0"
  s.source       = { :http => "https://paas-sdk.oss-cn-shanghai.aliyuncs.com/paas/imp/ios/release-pod-sdk/#{s.version}.zip"}
  s.pod_target_xcconfig = {
    'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'
  }
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }	

  s.dependency 'AliInteractiveRoomBundle', '~> 2.0'

  s.vendored_frameworks = "#{s.version}/AliStandardLiveRoomBundle.framework"
  s.frameworks = 'Foundation', 'UIKit'
  s.resource_bundles = {"AliStandardLiveRoomResource" => ["#{s.version}/AliStandardLiveRoomBundleResource/ASLRBLiveRoomAssets.xcassets"]}
  # s.libraries ='z', 'c++','resolv'
   
  #s.frameworks = 'VideoToolBox','MediaPlayer'
  #s.libraries = 'z'  
  s.requires_arc = true
   

end