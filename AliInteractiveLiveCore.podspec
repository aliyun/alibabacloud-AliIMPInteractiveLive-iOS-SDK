Pod::Spec.new do |s|
  s.name         = "AliInteractiveLiveCore"
  s.version      = "1.8.0-rc2"
  s.summary      = "AliInteractiveLiveCore."
  s.description  = <<-DESC
                   It's an SDK for aliyun interactive live core, which implement by Objective-C.
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

  s.dependency 'AlivcLivePusher', '~> 4.2'

  s.vendored_frameworks = "#{s.version}/AliInteractiveLiveCore.framework"
  s.frameworks = 'Foundation', 'UIKit', 'CoreMotion'
  # s.libraries ='z', 'c++','resolv'
   
  #s.frameworks = 'VideoToolBox','MediaPlayer'
  s.libraries ='compression', 'c++'
  s.requires_arc = true
   

end