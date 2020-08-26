Pod::Spec.new do |s|
    s.name         = "EkoChat"
    s.version      = "3.2.7"
    s.summary      = "An SDK for messaging provided by Upstra."
    s.description  = <<-DESC
    A powerful chat messaging tools for productivity powered by Upstra.
    DESC
    s.homepage     = "https://docs.upstra.co/ios/changelog"
    s.license = { :type => 'Copyright', :text => <<-LICENSE
                   Copyright 2020
                   Permission is granted to Eko Communications
                  LICENSE
                }
    s.author             = { "$(git config user.name)" => "$(git config user.email)" }
    s.source       = { :git => "https://github.com/EkoCommunications/EkoMessagingSDK.git", :tag => "#{s.version}" }
    s.vendored_frameworks = 'EkoChat.framework', 'Realm.framework'
    s.platform = :ios
    s.swift_version = "5"
    s.ios.deployment_target  = '9.0'
end
