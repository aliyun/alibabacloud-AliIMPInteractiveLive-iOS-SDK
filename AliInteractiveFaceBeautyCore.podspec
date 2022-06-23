Pod::Spec.new do |s|
  s.name         = "AliInteractiveFaceBeautyCore"
  s.version      = "2.0.0-rc5"
  s.summary      = "AliInteractiveFaceBeautyCore."
  s.description  = <<-DESC
                   It's an SDK for aliyun interactive face beauty core, which implement by Objective-C.
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

  s.dependency 'Queen', '1.9.1-official-pro'

  s.vendored_frameworks = "#{s.version}/AliInteractiveFaceBeautyCore.framework"
  s.frameworks = 'Foundation', 'UIKit', 'CoreMotion'
  s.resource_bundles = {"AliInteractiveFaceBeautyCoreResource" => ["#{s.version}/AIRBFaceBeautyCoreResource/*"]}
  # s.libraries ='z', 'c++','resolv'
   
  #s.frameworks = 'VideoToolBox','MediaPlayer'
  s.requires_arc = true
   

end