Pod::Spec.new do |s|
  s.name         = "AliInteractiveRoomBundle"
  s.version      = "1.4.1.20211104007"
  s.summary      = "AliInteractiveRoomBundle."
  s.description  = <<-DESC
                   It's an SDK for aliyun interactive live, which implement by Objective-C.
                   DESC
  s.homepage     = "https://github.com/aliyun/alibabacloud-AliIMPInteractiveLive-iOS-SDK"
  s.license      = { :type => "MIT", :file => "LICENSE" }
  s.author       = { "aliyunvideo" => "weihe.whq@alibaba-inc.com"}
  s.platform     = :ios
  s.platform     = :ios, "10.0"
  s.source       = { :git => "https://github.com/aliyun/alibabacloud-AliIMPInteractiveLive-iOS-SDK.git", :tag => "#{s.version}" }
  s.pod_target_xcconfig = {
    'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'
  }
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }	

  s.vendored_frameworks = 'AliInteractiveRoomBundle.framework'
  s.frameworks = 'Foundation', 'UIKit', 'SystemConfiguration', 'CoreTelephony'
  s.libraries ='z', 'c++','resolv'
   
  #s.frameworks = 'VideoToolBox','MediaPlayer'
  s.requires_arc = true
   

end