/**********************************************************************
* Copyright (c) 2008-2013, Alliance for Sustainable Energy.  
*  All rights reserved.
*  
*  This library is free software; you can redistribute it and/or
*  modify it under the terms of the GNU Lesser General Public
*  License as published by the Free Software Foundation; either
*  version 2.1 of the License, or (at your option) any later version.
*  
*  This library is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
*  Lesser General Public License for more details.
*  
*  You should have received a copy of the GNU Lesser General Public
*  License along with this library; if not, write to the Free Software
*  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
**********************************************************************/

#ifndef UTILITIES_CLOUD_AWSPROVIDER_IMPL_HPP
#define UTILITIES_CLOUD_AWSPROVIDER_IMPL_HPP

#include <utilities/cloud/CloudProvider_Impl.hpp>
#include <utilities/cloud/AWSProvider.hpp>

#include <QProcess>

namespace openstudio{
namespace detail{

  /// AWSSettings_Impl is a CloudSettings_Impl.
  class UTILITIES_API AWSSettings_Impl : public CloudSettings_Impl {
   public:

    /** @name Constructor */
    //@{

    /// default constructor, loads defaults from settings
    AWSSettings_Impl();

    /** Constructor provided for deserialization; not for general use. */
    AWSSettings_Impl(const UUID& uuid,
                     const UUID& versionUUID);

    //@}
    /** @name Destructors */
    //@{

    /// virtual destructor
    virtual ~AWSSettings_Impl();

    //@}
    /** @name Inherited members */
    //@{

    virtual std::string cloudProviderType() const;

    virtual std::string userAgreementText() const;

    virtual bool userAgreementSigned() const;

    virtual void signUserAgreement(bool agree);

    virtual bool loadSettings(bool overwriteExisting = false);

    virtual bool saveToSettings(bool overwriteExisting = false) const;

    //@}
    /** @name Class members */
    //@{
    //@}
   private:
    // configure logging
    REGISTER_LOGGER("utilities.cloud.AWSSettings");
  };

  /// AWSSession_Impl is a CloudSession_Impl.
  class UTILITIES_API AWSSession_Impl : public CloudSession_Impl {
  public:
    /** @name Constructor */
    //@{

    AWSSession_Impl(const std::string& sessionId,
                        const boost::optional<Url>& serverUrl,
                        const std::vector<Url>& workerUrls);

    /** Constructor provided for deserialization; not for general use. */
    AWSSession_Impl(const UUID& uuid,
                        const UUID& versionUUID,
                        const std::string& sessionId,
                        const boost::optional<Url>& serverUrl,
                        const std::vector<Url>& workerUrls);

    //@}
    /** @name Destructors */
    //@{

    virtual ~AWSSession_Impl();

    //@}
    /** @name Inherited members */
    //@{

    virtual std::string cloudProviderType() const;

    //@}
    /** @name Class members */
    //@{

    //@}

  private:
    // configure logging
    REGISTER_LOGGER("utilities.cloud.AWSSession");
  };

  /// AWSProvider is a CloudProvider that provides access to Amazon EC2 and CloudWatch services.
  class UTILITIES_API AWSProvider_Impl : public CloudProvider_Impl {

    Q_OBJECT

  public:

    /** @name Constructor */
    //@{

    /// default constructor
    AWSProvider_Impl();

    //@}
    /** @name Destructors */
    //@{

    /// virtual destructor
    virtual ~AWSProvider_Impl() {};

    //@}
    /** @name Inherited members */
    //@{

    /// returns the name of this type of cloud provider, e.g. 'AWSProvider'
    /// blocking call
    virtual std::string type() const;

    /// returns the user agreement text
    /// blocking call
    virtual std::string userAgreementText() const;

    /// returns true if the user has signed the user agreement
    /// blocking call
    virtual bool userAgreementSigned() const;

    /// signs the user agreement if passed in true, unsigns if passed in false
    /// blocking call
    virtual void signUserAgreement(bool agree);

    /// returns true if this computer is connected to the internet
    /// blocking call, clears errors and warnings
    virtual bool internetAvailable() const;

    /// returns true if the cloud service can be reached (e.g. ping)
    /// blocking call, clears errors and warnings
    virtual bool serviceAvailable() const;

    /// returns true if the cloud service validates user credentials
    /// blocking call, clears errors and warnings
    virtual bool validateCredentials() const;

    /// returns the current settings
    /// blocking call
    virtual CloudSettings settings() const;

    /// returns true if can assign settings
    /// blocking call, clears errors and warnings
    virtual bool setSettings(const CloudSettings& settings);

    /// returns the current session id
    /// blocking call
    virtual CloudSession session() const;

    /// returns true if can connect to a previously started sessionID using data in QSettings
    /// blocking call, clears errors and warnings
    virtual bool reconnect(const CloudSession& session);

    /// returns the ip address of the cloud server if it is started and running
    virtual boost::optional<Url> serverUrl() const;

    /// returns true if the cloud server successfully begins to start the server node
    /// returns false if terminated
    /// non-blocking call, clears errors and warnings
    virtual bool startServer();

    /// returns the ip address of all cloud workers that are started and running
    virtual std::vector<Url> workerUrls() const;

    /// returns the number of workers to be requested
    virtual unsigned numWorkers() const;

    /// returns true if the cloud server successfully begins to start all worker nodes
    /// returns false if terminated
    /// non-blocking call, clears errors and warnings
    virtual bool startWorkers();

    /// returns true if the server and all workers are running
    virtual bool running() const;

    /// returns true if the cloud server successfully begins to stop all nodes
    /// returns false if not running
    /// non-blocking call, clears errors and warnings
    virtual bool terminate();

    /// returns true if terminate has been called
    virtual bool terminated() const;

    /// returns errors generated by the last operation
    virtual std::vector<std::string> errors() const;
    
    /// returns warnings generated by the last operation
    virtual std::vector<std::string> warnings() const;

    //@}
    /** @name Class members */
    //@{

    // returns the cloud provider type
    static std::string cloudProviderType();

    // returns the AWS access key
    std::string accessKey() const;

    // returns the AWS secret key
    std::string secretKey() const;

    // performs a cursory regex validation of both keys, and returns true if they match
    bool setKeys(std::string accessKey, std::string secretKey) const;

    // run an action against the AWS-SDK ruby gem
    QVariantMap awsRequest(std::string request, std::string service = "EC2") const;

    // set the number of worker nodes to start
    void setNumWorkers(const unsigned numWorkers);

    //@}

  private slots:

    void onServerStarted(int, QProcess::ExitStatus);
    void onWorkerStarted(int, QProcess::ExitStatus);
    void onServerStopped(int, QProcess::ExitStatus);
    void onWorkerStopped(int, QProcess::ExitStatus);

  private:

    AWSSettings m_awsSettings;
    AWSSession m_awsSession;

    bool loadCredentials() const;
    bool saveCredentials() const;
    bool validAccessKey(std::string accessKey) const;
    bool validSecretKey(std::string secretKey) const;

    mutable std::string m_accessKey;
    mutable std::string m_secretKey;
    mutable bool m_validAccessKey;
    mutable bool m_validSecretKey;

    unsigned m_numWorkers;

    QProcess* m_startServerProcess;
    QProcess* m_startWorkerProcess;
    QProcess* m_stopServerProcess;
    QProcess* m_stopWorkerProcess;
    bool m_serverStarted;
    bool m_workerStarted;
    bool m_serverStopped;
    bool m_workerStopped;
    bool m_terminated;

    mutable std::vector<std::string> m_errors;
    mutable std::vector<std::string> m_warnings;

    void clearErrorsAndWarnings() const;
    void logError(const std::string& error) const;
    void logWarning(const std::string& warning) const;

    // configure logging
    REGISTER_LOGGER("utilities.cloud.AWSProvider");

  };

} // detail
} // openstudio

#endif // UTILITIES_CLOUD_AWSPROVIDER_IMPL_HPP
